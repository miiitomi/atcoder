#include <bits/stdc++.h>
using namespace std;

struct D {
    pair<int, int> m;
    pair<int, int> l;
    pair<int, int> r;
    int s;

    D() {
        m = make_pair(0, 0);
        l = make_pair(0, 0);
        r = make_pair(0, 0);
        s = 0;
    }

    void reverse() {
        swap(m.first, m.second);
        swap(l.first, l.second);
        swap(r.first, r.second);
    }
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = D(); // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    void set_size(int k, int s) {
        data[k].s = s;
        if (k < n-1) {
            set_size(k*2+1, s/2);
            set_size(k*2+2, s/2);
            data[k] = X_operation(data[k*2+1], data[k*2+2]);
        } else {
            data[k].m = make_pair(0, 1);
            data[k].l = make_pair(0, 1);
            data[k].r = make_pair(0, 1);
        }
    }

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
        set_size(0, n);
    }

    X X_operation(X a, X b) {
        D d = D();
        d.s = a.s + b.s;

        if (a.s == a.l.first) d.l.first = a.l.first + b.l.first;
        else d.l.first = a.l.first;
        if (a.s == a.l.second) d.l.second = a.l.second + b.l.second;
        else d.l.second = a.l.second;

        if (b.r.first == b.s) d.r.first = a.r.first + b.r.first;
        else d.r.first = b.r.first;
        if (b.r.second == b.s) d.r.second = a.r.second + b.r.second;
        else d.r.second = b.r.second;

        d.m.first = max(a.m.first, max(b.m.first, a.r.first + b.l.first));
        d.m.second = max(a.m.second, max(b.m.second, a.r.second + b.l.second));

        return d;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        if (a != b) return 1;
        else return 0;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        if (m == M_init) return x;
        D d = x;
        d.reverse();
        return d;
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
    int query(int a, int b) {
        return _sub_query(a, b, 0, 0, n).m.first;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    LazySegmentTree<D, int> lst(N);
    for (int i = 0; i < N; i++) if (S[i] == '1') lst.update(i, i+1, 1);

    vector<int> V;
    V.reserve(Q);

    for (int q = 0; q < Q; q++) {
        int c, l, r;
        cin >> c >> l >> r;
        l--;
        r--;
        if (c == 1) lst.update(l, r+1, 1);
        else V.push_back(lst.query(l, r+1));
    }

    for (int v : V) cout << v << endl;
}
