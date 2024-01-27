#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmin(ll &l, ll r) {
    if (l > r) l = r;
}

int N, M;
vector<vector<int>> G;
vector<vector<ll>> W;
vector<vector<ll>> d;

void floyd_warshall() {
    d = W;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    W.assign(N, vector<ll>(N, INF));
    for (int u = 0; u < N; u++) W[u][u] = 0;
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        cin >> W[u][v];
    }
    floyd_warshall();

    vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));
    for (int u = 0; u < N; u++) dp[(1 << u)][u] = 0;
    for (int s = 1; s < (1 << N); s++) {
        for (int u = 0; u < N; u++) {
            if (dp[s][u] == INF) continue;
            for (int v = 0; v < N; v++) {
                chmin(dp[s | (1 << v)][v], dp[s][u] + d[u][v]);
            }
        }
    }
    ll ans = *min_element(dp[(1 << N)-1].begin(), dp[(1 << N)-1].end());
    if (ans >= 1e+17) cout << "No" << endl;
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
