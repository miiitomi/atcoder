// https://atcoder.jp/contests/abc282/tasks/abc282_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<ll>> G;
bool bipartite = true;
vector<int> c;

void dfs(int u) {
    for (int v : G[u]) {
        if (c[v] == 0) {
            c[v] = -c[u];
            dfs(v);
        } else {
            if (c[u] == c[v]) bipartite = false;
        }
    }
}

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
    cin >> N >> M;
    G.resize(N);
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }
    c.assign(N, 0);
    for (int u = 0; u < N; u++) {
        if (u != uf.root(u)) continue;
        c[u] = 1;
        dfs(u);
    }
    if (!bipartite) {
        cout << 0 << endl;
        return;
    }
    vector<pair<ll,ll>> cnt(N, {0,0});
    for (int u = 0; u < N; u++) {
        int r = uf.root(u);
        if (c[u] > 0) cnt[r].first++;
        else cnt[r].second++;
    }
    ll ans = 0;
    for (int u = 0; u < N; u++) {
        if (u != uf.root(u)) continue;
        ans += 2*cnt[u].first*cnt[u].second + (N-uf.size(u))*(uf.size(u));
    }
    ans /= 2;
    ans -= M;
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
