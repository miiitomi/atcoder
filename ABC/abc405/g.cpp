#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1), I(1e+6, 1);

struct Mo {
    struct Query {
        int id, l, r, x, l_;
        Query(int i, int l, int r, int x, int B): id(i), l(l), r(r), x(x) {l_ = l / B;}
    };

    int N, Q, B = 1000, W = 500;
    vector<Query> queries;
    vector<mint> ans;
    vector<int> A;
    int left=0, right=-1;

    /* Update below! */
    vector<int> sum_all, sum_sqrt;
    vector<mint> prod_all, prod_sqrt;

    void _add(int a) {
        // TODO: Set add function used in query().
        sum_all[a]++;
        sum_sqrt[a/W]++;
        prod_all[a] = I[sum_all[a]];
        prod_sqrt[a/W] *= F[sum_all[a]-1] * I[sum_all[a]];
    }
    void _remove(int a) {
        // TODO: Set remove function used in query().
        sum_all[a]--;
        sum_sqrt[a/W]--;
        prod_all[a] = I[sum_all[a]];
        prod_sqrt[a/W] *= F[sum_all[a]+1] * I[sum_all[a]];
    }
    void _query(Query &q) {
        while (right < q.r) {
            right++;
            _add(A[right]);    // TODO: Update arg.
        }
        while (q.l < left) {
            left--;
            _add(A[left]);    // TODO: Update arg.
        }
        while (left < q.l) {
            _remove(A[left]);    // TODO: Update arg.
            left++;
        }
        while (q.r < right) {
            _remove(A[right]);    // TODO: Update arg.
            right--;
        }
        int sum = 0;
        mint prod = 1;
        for (int i = 0; i < q.x && i < N; ) {
            if (q.x < i + W) {
                sum += sum_all[i];
                prod *= prod_all[i];
                i++;
            } else {
                sum += sum_sqrt[i/W];
                prod *= prod_sqrt[i/W];
                i += W;
            }
        }
        ans[q.id] = F[sum] * prod;
    }
    Mo(int n, int q): N(n), Q(q) {
        queries.assign(Q, {0, 0, 0, 0, B});
        ans.assign(Q, 0);
        A.resize(N);
        sum_all.assign(N, 0);
        sum_sqrt.assign((N + W-1)/W, 0);
        prod_all.assign(N, 1);
        prod_sqrt.assign((N + W - 1) / W, 1);
    }
    /* Up to here! */

    void add_query(int i, int l, int r, int x) {
        // Add i'th query for [l, r] . (REMARK: closed interval!)
        queries[i] = Query(i, l, r, x, B);
    }

    void run() {
        sort(queries.begin(), queries.end(), [](Query &q1, Query &q2){
            if (q1.l_ != q2.l_) return q1.l_ < q2.l_;
            return q1.r < q2.r;
        });
        for (Query &q : queries) _query(q);
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    Mo mo(N, Q);
    for (int i = 0; i < N; i++) {
        cin >> mo.A[i];
        mo.A[i]--;
    }
    for (int q = 0; q < Q; q++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--; x--;
        mo.add_query(q, l, r, x);
    }
    mo.run();
    for (auto &a: mo.ans) cout << a.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+6; x++) {
        F[x] = x * F[x-1];
        I[x] = F[x].inv();
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
