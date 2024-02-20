// https://atcoder.jp/contests/abc322/tasks/abc322_f
#include <bits/stdc++.h>
using namespace std;

struct Data {
    int s=0, l0=0, l1=0, r0=0, r1=0, m0=0, m1=0;
    Data() {}

    Data(int _x) {
        s = 1;
        if (_x == 0) {
            l0 = 1;
            r0 = 1;
            m0 = 1;
        } else  if (_x == 1) {
            l1 = 1;
            r1 = 1;
            m1 = 1;
        }
    }
    void swp() {
        swap(l0, l1);
        swap(r0, r1);
        swap(m0, m1);
    }
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = Data(); // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        if (a.s == 0) return b;
        else if (b.s == 0) return a;

        X c = Data();
        c.s = a.s + b.s;
        if (a.l0 == a.s) c.l0 = a.s + b.l0; else c.l0 = a.l0;
        if (a.l1 == a.s) c.l1 = a.s + b.l1; else c.l1 = a.l1;
        if (b.r0 == b.s) c.r0 = a.r0 + b.s; else c.r0 = b.r0;
        if (b.r1 == b.s) c.r1 = a.r1 + b.s; else c.r1 = b.r1;
        c.m0 = max(a.m0, max(b.m0, a.r0 + b.l0));
        c.m1 = max(a.m1, max(b.m1, a.r1 + b.l1));

        return c;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return (a + b) % 2;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        if (m == M_init) return x;
        x.swp();
        return x;
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

    void update(int i, X a) {
        i = n - 1 + i;
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = X_operation(data[i*2 + 1], data[i*2 + 2]);
        }
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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    LazySegmentTree<Data, int> lst(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == '0') lst.update(i, Data(0));
        else lst.update(i, Data(1));
    }

    while (Q--) {
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        r--;
        if (c == 1) {
            lst.update(l, r+1, 1);
        } else {
            Data res = lst.query(l, r+1);
            cout << res.m1 << "\n";
        }
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
