#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct Data {
    mint x;
    int siz;
    Data(mint x, int siz): x(x), siz(siz) {}
};

struct Act {
    mint s, t;
    Act(mint s, mint t): s(s), t(t) {}
    bool operator==(const Act &other) {return s == other.s && t == other.t;}
    bool operator!=(const Act &other) {return s != other.s || t == other.t;}
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = Data(0, 0); // TODO: Set initial value of data X.
    M M_init = Act(1, 0); // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
        for (int k = 2*n-2; k >= 0; k--) {
            if (k >= n-1) data[k].siz = 1;
            else data[k].siz = data[2*k+1].siz + data[2*k+2].siz;
        }
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return Data(a.x + b.x, a.siz + b.siz);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        if (b == M_init) return a;
        if (a == M_init) return b;
        return Act(a.s*b.s, a.t*b.s + b.t);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        if (m == M_init) return x;
        return Data(x.x * m.s + x.siz * m.t, x.siz);
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
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<Data, Act> lst(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        lst.update(i, i+1, Act(0, a));
    }

    while (Q--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            cout << lst.query(l, r).x.val() << endl;
        } else {
            int s, t;
            cin >> s >> t;
            lst.update(l, r, Act(s, t));
        }
    }
}
