// https://atcoder.jp/contests/abc253/tasks/abc253_f
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
        return a + b;
    }

    X X_M_operation(X x, M m) {
        return (x + m);
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

struct Query {
    int t=0, k=0, l=0, r=0, i=0, j=0, x=0;
    vector<int> v;
    Query(int t_, int k_): t(t_), k(k_) {}

    void add_query(int l_, int r_, int x_) {
        l = l_;
        r = r_;
        x = x_;
    }

    void add_query(int l_, int r_) {
        if (k == 2) {
            i = l_;
            x = r_;
        } else {
            i = l_;
            j = r_;
        }
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> v(N);
    vector<Query> queries;
    for (int t = 0; t < Q; t++) {
        int k;
        cin >> k;
        queries.push_back(Query(t, k));
        if (k == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            queries.back().add_query(l, r, x);
        } else if (k == 2) {
            int i, x;
            cin >> i >> x;
            i--;
            queries.back().add_query(i, x);
            v[i].push_back(t);
        } else {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            queries.back().add_query(i, j);
            if (!v[i].empty()) {
                int T = v[i].back();
                queries[T].v.push_back(j);
            }
        }
    }

    LazySegmentTree<ll, ll> lst(M);
    map<pair<ll, ll>, pair<ll, ll>> x;

    for (Query &q : queries) {
        if (q.k == 1) {
            lst.update(q.l, q.r+1, q.x);
        } else if (q.k == 2) {
            for (int j : q.v) {
                x[make_pair(q.i, j)] = make_pair(q.x, lst.query(j, j+1));
            }
        } else {
            ll ans = lst.query(q.j, q.j+1);
            if (x.count(make_pair(q.i, q.j))) {
                ans += x[make_pair(q.i, q.j)].first - x[make_pair(q.i, q.j)].second;
            }
            cout << ans << "\n";
        }
    }
}
