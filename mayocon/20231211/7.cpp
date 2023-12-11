// https://atcoder.jp/contests/abc238/tasks/abc238_g
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<bool> is_prime(1e+3, true);
vector<int> primes;

vector<vector<int>> V, W;

constexpr int logn = 20; 
constexpr int maxn = 1 << logn;
 
ll hilbertorder(int x, int y) {
    ll d = 0;
    for (int s = 1<<logn-1; s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (ry) continue;
		if (rx) {
			x = maxn - x;
			y = maxn - y;
		}
		swap(x, y);
    }
    return d;
}

struct Mo {
    struct Query {
        int id, l, r, l_;
        ll o;
        Query(int i, int l, int r, int b = 1): id(i), l(l), r(r) {
            l_ = l / b;
            o = hilbertorder(l, r);
        }
    };

    int N, Q, B;
    vector<Query> queries;
    vector<int> ans;
    vector<ll> ord;
    int left=0, right=-1;

    /* Update below! */
    vector<int> state;    // TODO: Set state variables.
    int tmp = 0;    // TODO: Set initial tmp answer.

    void _add(int i) {
        for (int j = 0; j < (int)V[i].size(); j++) {
            int q = V[i][j], n = W[i][j];
            if (state[q] != 0) tmp--;
            state[q] += n;
            if (state[q] > 2) state[q] -= 3;
            if (state[q] != 0) tmp++;
        }
    }
    void _remove(int i) {
        for (int j = 0; j < (int)V[i].size(); j++) {
            int q = V[i][j], n = W[i][j];
            if (state[q] != 0) tmp--;
            state[q] -= n;
            if (state[q] < 0) state[q] += 3;
            if (state[q] != 0) tmp++;
        }
    }
    void _query(Query &q) {
        while (right < q.r) {
            right++;
            _add(right);    // TODO: Update arg.
        }
        while (q.l < left) {
            left--;
            _add(left);    // TODO: Update arg.
        }
        while (left < q.l) {
            _remove(left);    // TODO: Update arg.
            left++;
        }
        while (q.r < right) {
            _remove(right);    // TODO: Update arg.
            right--;
        }
        ans[q.id] = tmp;
    }
    Mo(int n, int q): N(n), Q(q) {
        B = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);  // TODO: Set state variable.
        state.assign(primes.size(), 0);
        ord.resize(Q);
    }
    /* Up to here! */

    void add_query(int i, int l, int r) {
        // Add i'th query for [l, r] . (REMARK: closed interval!)
        queries[i] = Query(i, l, r, B);
        ord[i] = hilbertorder(l, r);
    }

    void run() {
        sort(queries.begin(), queries.end(), [](Query &q1, Query &q2){
            return q1.o < q2.o;
        });
        for (Query &q : queries) _query(q);
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int x = 2; x < 1e+3; x++) {
        if (is_prime[x]) {
            primes.push_back(x);
            for (int y = 2*x; y < 1e+3; y += x) {
                is_prime[y] = false;
            }
        }
    }

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    V.resize(N);
    W.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < (int)primes.size(); j++) {
            int x = primes[j];
            if (x*x > A[i]) break;
            if (A[i] % x == 0) {
                int cnt = 0;
                while (A[i] % x == 0) {
                    A[i] /= x;
                    cnt++;
                }
                cnt %= 3;
                if (cnt != 0) {
                    V[i].push_back(j);
                    W[i].push_back(cnt);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != 1) {
            if (find(primes.begin(), primes.end(), A[i]) == primes.end()) {
                primes.push_back(A[i]);
            }
        }
    }

    sort(primes.begin(), primes.end());
    for (int i = 0; i < N; i++) {
        if (A[i] != 1) {
            int j = distance(primes.begin(), lower_bound(primes.begin(), primes.end(), A[i]));
            V[i].push_back(j);
            W[i].push_back(1);
        }
    }

    Mo mo(N, Q);

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        mo.add_query(q, l, r);
    }

    mo.run();
    for (int x : mo.ans) {
        if (x == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}
