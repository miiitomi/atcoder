#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct Fenwick {
    int n;
    vector<T> data;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    T sum(int i) {
        // compute sum of a[i] with i in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

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
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<Fenwick<ll>> f(2, Fenwick<ll>(N));
    while (Q--) {
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        x--;
        y--;
        if (t == 0) {
            uf.unite(x, y);
            if (f[x%2].sum(x, x+1) == 0) f[x%2].add(x, v);
        } else {
            if (!uf.issame(x, y)) {
                cout << "Ambiguous\n";
            } else if (x <= y) {
                ll rhs = f[x%2].sum(x, y) - f[1-x%2].sum(x, y);
                if ((y-x)%2) cout << rhs - v << "\n";
                else cout << v - rhs << "\n";
            } else {
                ll rhs = f[y%2].sum(y, x) - f[1-y%2].sum(y, x);
                if ((x-y)%2) cout << rhs - v << "\n";
                else cout << rhs + v << "\n";
            }
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
