// https://atcoder.jp/contests/abc128/tasks/abc128_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = INF; // TODO: Set initial value of data X.
    M M_init = INF; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return min(a, b);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return min(a, b);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return min(x, m);
    }

    void eval(int k) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = X_M_operation(data[k], lazy[k]);
        lazy[k] = M_init;
    }

    void _update(int a, int b, M m, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {
            lazy[k] = M_operation(lazy[k], m);
            eval(k);
        } else if (a < r && l < b) {
            _update(a, b, m, k * 2 + 1, l, (l + r) / 2);
            _update(a, b, m, k * 2 + 2, (l + r) / 2, r);
            data[k] = X_operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // Update data[i] with i in [a, b) by multiplying m in M.
    void update(int a, int b, M m) {
        _update(a, b, m, 0, 0, n);
    }

    X _sub_query(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {
            return X_init;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            X vl = _sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = _sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return X_operation(vl, vr);
        }
    }

    // Return the answer in [a, b)
    X query(int a, int b) {
        return _sub_query(a, b, 0, 0, n);
    }
};

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<vector<ll>> V(N, vector<ll>(3));
    for (int i = 0; i < N; i++) {
        cin >> V[i][1] >> V[i][2] >> V[i][0];
    }
    sort(V.begin(), V.end());
    vector<ll> D(Q);
    for (int i = 0; i < Q; i++) cin >> D[i];
    sort(D.begin(), D.end());

    LazySegmentTree<ll,ll> lst(Q);
    for (auto &v : V) {
        ll x = v[0], s = v[1], t = v[2];
        s -= x;
        t -= x;
        if (t < 0) continue;
        int i = distance(D.begin(), lower_bound(D.begin(), D.end(), s));
        int j = distance(D.begin(), lower_bound(D.begin(), D.end(), t));
        if (i == j) continue;
        lst.update(i, j, x);
    }

    for (int i = 0; i < Q; i++) {
        ll ans = lst.query(i, i+1);
        if (ans == INF) ans = -1;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
