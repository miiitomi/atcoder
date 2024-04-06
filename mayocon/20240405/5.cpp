// https://atcoder.jp/contests/abc174/tasks/abc174_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
vector<int> A;

ll hilbertorder(ll x, ll y) {
    ll maxn = 1;
    while (maxn < n) maxn *= 2LL;
    ll rx, ry, d = 0;
    for (ll s = (maxn >> 1); s; s >>= 1) {
        rx = (x & s)>0, ry = (y & s)>0;
        d += s * s * ((rx * 3) ^ ry);
        if (ry) continue;
        if (rx) {
        x = maxn-1 - x;
        y = maxn-1 - y;
        }
        swap(x, y);
    }
    return d;
}

template <typename T>
struct Mo {
    struct Query {
        ll id, l, r, l_;
        Query(int i, int l, int r): id(i), l(l), r(r) {l_ = hilbertorder(l, r);}
    };

    int N, Q;
    vector<Query> queries;
    vector<T> ans;
    int left=0, right=-1;

    /* Update below! */
    vector<T> state;    // TODO: Set state variables.
    T tmp = 0;    // TODO: Set initial tmp answer.

    void _add(int a) {
        state[a]++;
        if (state[a] == 1) tmp++;
        // TODO: Set add function used in query().
    }
    void _remove(int a) {
        state[a]--;
        if (state[a] == 0) tmp--;
        // TODO: Set remove function used in query().
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
        ans[q.id] = tmp;
    }
    Mo(int n, int q): N(n), Q(q) {
        queries.assign(Q, {0, 0, 0});
        ans.assign(Q, 0);
        state.assign(N, 0);  // TODO: Set state variable.
    }
    /* Up to here! */

    void add_query(int i, int l, int r) {
        // Add i'th query for [l, r] . (REMARK: closed interval!)
        queries[i] = Query(i, l, r);
    }

    void run() {
        state.assign(n, 0);
        sort(queries.begin(), queries.end(), [](Query &q1, Query &q2){
            if (q1.l_ != q2.l_) return q1.l_ < q2.l_;
            return q1.r < q2.r;
        });
        for (Query &q : queries) _query(q);
    }
};

void solve() {
    cin >> n >> q;
    A.resize(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    Mo<int> mo(n, q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        mo.add_query(i, l, r);
    }
    mo.run();
    for (int x : mo.ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
