#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<vector<pair<ll,ll>>> G;
vector<ll> x;

void dfs(ll u) {
    for (auto &e : G[u]) {
        auto [v, w] = e;
        if (x[v] != -INF) continue;
        x[v] = x[u] + w;
        dfs(v);
    }
}

void solve() {
    ll N, M;
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, -w});
    }
    x.assign(N, -INF);
    for (ll u = 0; u < N; u++) {
        if (x[u] == -INF) {
            x[u] = 0;
            dfs(u);
        }
    }
    for (ll a : x) cout << a << " ";
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
