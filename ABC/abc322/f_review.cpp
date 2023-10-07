#include <bits/stdc++.h>
using namespace std;

struct State {
    int size = 0;
    vector<int> m{0, 0};
    vector<int> l{0, 0};
    vector<int> r{0, 0};

    void reverse() {
        swap(m[0], m[1]);
        swap(l[0], l[1]);
        swap(r[0], r[1]);
    }
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = State(); // TODO: Set initial value of data X.
    M M_init = 0 ; // TODO: Set initial value of act M.

    void initialize(int k) {
        if (k < n-1) {
            initialize(k * 2 + 1);
            initialize(k * 2 + 2);
            X_operation(data[k*2+1], data[k*2+2], data[k]);
        } else {
            data[k].size = 1;
            data[k].m[0] = 1;
            data[k].l[0] = 1;
            data[k].r[0] = 1;
        }
    }

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
        initialize(0);
    }

    void X_operation(X &a, X &b, X &c) {
        c.size = a.size + b.size;
        for (int k = 0; k <= 1; k++) {
            if (a.l[k] == a.size) c.l[k] = a.size + b.l[k];
            else c.l[k] = a.l[k];
            if (b.r[k] == b.size) c.r[k] = b.size + a.r[k];
            else c.r[k] = b.r[k];
            c.m[k] = max(a.m[k], max(b.m[k], a.r[k] + b.l[k]));
        }
        return;
    }

    M M_operation(M a, M b) {
        if (a == b) return 0;
        else return 1;
    }

    void X_M_operation(X &x, M m) {
        if (m == M_init) return;
        x.reverse();
        return;
    }

    void eval(int k) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        X_M_operation(data[k], lazy[k]);
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
            X_operation(data[k * 2 + 1], data[k * 2 + 2], data[k]);
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
            X c = State();
            X_operation(vl, vr, c);
            return c;
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
    string S;
    cin >> S;

    LazySegmentTree<State, int> lst(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') lst.update(i, i+1, 1);
    }

    for (int q = 0; q < Q; q++) {
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        r--;
        if (c == 1) lst.update(l, r+1, 1);
        else cout << lst.query(l, r+1).m[1] << endl;
    }
}
