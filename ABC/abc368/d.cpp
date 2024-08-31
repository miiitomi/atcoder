#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, K;
vector<vector<ll>> G;
vector<ll> V;
vector<bool> used;

void dfs(int u, int p) {
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (used[v]) used[u] = true;
    }
}

void solve() {
    cin >> N >> K;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    V.resize(K);
    used.assign(N, false);
    for (int k = 0; k < K; k++) {
        cin >> V[k];
        V[k]--;
        used[V[k]] = true;
    }
    dfs(V[0], -1);
    ll ans = 0;
    for (ll u = 0; u < N; u++) ans += used[u];
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
