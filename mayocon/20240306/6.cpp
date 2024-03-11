// https://atcoder.jp/contests/abc173/tasks/abc173_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par, siz;
    int n;

    UnionFind(int n) : par(n, -1), siz(n, 1), n(n) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        n--;
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = make_pair(0, 0); // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
        for (int i = 0; i < n_; i++) data[n-1+i].second = 1;
        for (int i = n-2; i >= 0; i--) data[i].second = data[2*i+1].second + data[2*i+2].second;
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return make_pair(a.first + b.first, a.second + b.second);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a + b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return make_pair(x.first + m * x.second, x.second);
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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    LazySegmentTree<pair<ll,ll>,ll> lst(N);
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        for (int j : G[i]) if (j <= i) uf.unite(i, j);
        lst.update(i, i+1, uf.n - (N-i-1));
        sort(G[i].begin(), G[i].end());
        G[i].push_back(N);
        reverse(G[i].begin(), G[i].end());
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += lst.query(i, N).first;
        int x = i, y = -1;
        while (G[i].back() < i) G[i].pop_back();
        while (x != N) {
            lst.update(x, G[i].back(), y);
            x = G[i].back();
            G[i].pop_back();
            y++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
