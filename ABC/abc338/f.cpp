#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void chmin(ll &x, ll y) {
    if (x > y) x = y;
}

int N, M;
vector<vector<int>> G;
vector<vector<bool>> exists_edge;
vector<vector<int>> C;
const ll INF = 1e+18;

void dfs(int u, vector<bool> &reached, vector<int> &V) {
    reached[u] = true;
    for (int v: G[u]) {
        if (reached[v] || C[u][v] >= 0) continue;
        dfs(v, reached, V);
    }
    V.push_back(u);
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    exists_edge.assign(N, vector<bool>(N, false));
    C.assign(N, vector<int>(N, (int)1e+9));
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(v);
        exists_edge[u][v] = true;
        C[u][v] = w;
    }
    vector<bool> reached(N, false);
    vector<int> V;
    for (int u = 0; u < N; u++) if (!reached[u]) dfs(u, reached, V);
    reverse(V.begin(), V.end());

    vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));
    for (int u = 0; u < N; u++) dp[(1 << u)][u] = 0;
    for (int s = 1; s < (1 << N); s++) {
        for (int u : V) {
            if (dp[s][u] == INF) continue;
            for (int v : G[u]) {
                int t = s | (1 << v);
                chmin(dp[t][v], dp[s][u] + C[u][v]);
            }
        }
    }

    ll ans = *min_element(dp[(1 << N)-1].begin(), dp[(1 << N)-1].end());
    if (ans == INF) cout << "No" << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
