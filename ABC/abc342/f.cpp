#include <bits/stdc++.h>
using namespace std;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = make_pair(0.0, 1); // TODO: Set initial value of data X.
    M M_init = 0.0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return make_pair(a.first + b.first, a.second + b.second);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a+b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return make_pair(x.first + x.second*m, x.second);
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
    int N, L, D;
    cin >> N >> L >> D;
    LazySegmentTree<pair<double,int>, double> me(N+D+1), dealer(N+D+1);
    for (int x = 0; x <= N+D; x++) me.update(x, x+1, 0.0);
    for (int x = 0; x <= N+D; x++) dealer.update(x, x+1, 0.0);

    dealer.update(0, 1, 1.0);
    double p = 1.0 / (double)D;
    for (int y = 0; y < L; y++) {
        double q = dealer.query(y, y+1).first;
        dealer.update(y+1, y+D+1, q*p);
    }

    for (int x = N; x >= 0; x--) {
        double a = 1 - dealer.query(max(x, L), N+1).first;
        double b = p * me.query(x+1, x+D+1).first;
        me.update(x, x+1, max(a, b));
    }

    cout << me.query(0, 1).first << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
