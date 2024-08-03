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
vector<ll> color;

bool dfs(ll u) {
    for (ll v : G[u]) {
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            bool res = dfs(v);
            if (!res) return false;
        } else {
            if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
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
    color.assign(N, -1);
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }

    for (ll r = 0; r < N; r++) {
        if (r != uf.root(r)) continue;
        color[r] = 0;
        bool res = dfs(r);
        if (!res) {
            cout << 0 << endl;
            return;
        }
    }
    vector<vector<ll>> cnt(N, vector<ll>(2, 0));
    for (int r = 0; r < N; r++) {
        cnt[uf.root(r)][color[r]]++;
    }
    ll ans = 0;
    for (int r = 0; r < N; r++) {
        if (uf.root(r) != r) continue;
        ans += (cnt[r][0] + cnt[r][1]) * (N - (cnt[r][0] + cnt[r][1]));
        ans += 2*cnt[r][0]*cnt[r][1];
    }
    ans /= 2;
    ans -= M;
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
