#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll INF = 1e+18;

template<typename X, typename M> struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = {INF, INF}; // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

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
        return a+b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return {x.first-m, x.second};
    }

    void initialize(int i, X x) {
        i = n - 1 + i;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = X_operation(data[i*2 + 1], data[i*2 + 2]);
        }
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

int main() {
    ll N;
    cin >> N;
    LazySegmentTree<pair<ll,ll>, ll> lst(N);
    fenwick_tree<ll> ft(N);
    
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        lst.initialize(i, {a, i});
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        l--;
        ll ans = k*(r - l - ft.sum(l, r));
        lst.update(l, r, k);
        pair<ll,ll> p = lst.query(l, r);
        while (p.first <= 0) {
            ans += p.first;
            lst.update(p.second, p.second+1, -INF);
            ft.add(p.second, 1);
            p = lst.query(l, r);
        }
        cout << ans << "\n";
    }
}
