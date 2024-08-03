// https://atcoder.jp/contests/abc345/tasks/abc345_f
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

ll N, M, K;
vector<vector<pair<ll,ll>>> G;
vector<ll> par, par_edge_idx, num_child;

void dfs(ll u, ll p) {
    for (auto &e: G[u]) {
        ll idx = e.second, v = e.first;
        if (v == p) continue;
        par[v] = u;
        par_edge_idx[v] = idx;
        num_child[u]++;
        dfs(v, u);
    }
}

void solve() {
    cin >> N >> M >> K;
    G.resize(N);
    UnionFind uf(N);
    for (int i = 1; i <= M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        if (uf.issame(u, v)) continue;
        uf.unite(u, v);
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    par.assign(N, -1);
    par_edge_idx.assign(N, -1);
    num_child.assign(N, 0);
    ll S = 0;
    for (ll u = 0; u < N; u++) {
        if (u == uf.root(u)) {
            S += (uf.size(u)/2)*2;
            dfs(u, -1);
        }
    }

    if (K % 2 == 0 && K <= S) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }

    vector<vector<ll>> children(N);
    for (ll u = 0; u < N; u++) {
        if (num_child[u] == 0) {
            children[uf.root(u)].push_back(u);
        }
    }

    vector<bool> on(N, false);
    ll sum = 0;
    vector<ll> ans;

    for (ll r = 0; r < N && sum < K; r++) {
        if (r != uf.root(r)) continue;
        queue<ll> Q;
        for (ll c : children[r]) if (par[c] != -1) Q.push(c);
        while (!Q.empty() && sum < K) {
            ll u = Q.front();
            Q.pop();
            if (!on[u]) {
                on[u] = true;
                sum++;
                if (!on[par[u]]) {
                    on[par[u]] = true;
                    sum++;
                } else {
                    on[par[u]] = false;
                    sum--;
                }
                ans.push_back(par_edge_idx[u]);
            }
            num_child[par[u]]--;
            if (num_child[par[u]]==0 && par[par[u]] != -1) Q.push(par[u]);
        }
    }

    cout << ans.size() << "\n";
    for (ll x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
