// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = 0; // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return a + b;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a + b;
    }

    // X X_M_operation(X x, M m) {
    //     // TODO: Set operation on X x M
    //     if (m == M_init) return x;
    //     return x + m;
    // }

    void eval(int k, int l, int r) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] += lazy[k] * (r - l);
        lazy[k] = M_init;
    }

    void _update(int a, int b, M m, int k, int l, int r) {
        eval(k, l, r);
        if (a <= l && r <= b) {
            lazy[k] = M_operation(lazy[k], m);
            eval(k, l, r);
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
        eval(k, l, r);
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
    int N, Q;
    cin >> N >> Q;

    LazySegmentTree<ll, ll> lst(N);
    for (int i = 0; i < Q; i++) {
        ll c, s, t, x;
        cin >> c >> s >> t;
        if (c == 0) {
            cin >> x;
            lst.update(s-1, t, x);
        } else {
            cout << lst.query(s-1, t) << endl;
        }
    }
}
