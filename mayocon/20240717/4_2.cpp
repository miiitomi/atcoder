// https://atcoder.jp/contests/abc293/tasks/abc293_d
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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    UnionFind uf(N);
    while (M--) {
        ll u, v;
        char x, y;
        cin >> u >> x >> v >> y;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }

    vector<ll> v(N, 0), e(N, 0);
    for (int u = 0; u < N; u++) {
        int r = uf.root(u);
        v[r]++;
        e[r] += G[u].size();
    }

    ll X = 0, Y = 0;
    for (int u = 0; u < N; u++) {
        if (v[u] == 0) continue;
        if (2*v[u] == e[u]) X++;
        else Y++;
    }
    cout << X << " " << Y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
