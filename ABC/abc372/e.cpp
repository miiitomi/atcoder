#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

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
    ll N, Q;
    cin >> N >> Q;
    vector<set<ll>> st(N);
    for (ll i = 0; i < N; i++) st[i].insert(i);
    UnionFind uf(N);
    while (Q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll u, v;
            cin >> u >> v;
            u--; v--;
            u = uf.root(u);
            v = uf.root(v);
            if (uf.issame(u, v)) continue;
            uf.unite(u, v);
            ll r = uf.root(u);
            if (r == v) swap(u, v);
            if ((int)st[u].size() < (int)st[v].size()) swap(st[u], st[v]);
            for (ll x : st[v]) st[u].insert(x);
            st[v] = {};
        } else {
            ll v, k;
            cin >> v >> k;
            v--;
            v = uf.root(v);
            if ((int)st[v].size() < k) {
                cout << -1 << "\n";
                continue;
            }
            k--;
            auto iter = st[v].end();
            iter--;
            while (k--) iter--;
            cout << 1 + *iter << "\n";
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
