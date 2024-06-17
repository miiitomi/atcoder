// https://atcoder.jp/contests/abc338/tasks/abc338_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;

ll N, M;
vector<vector<pair<int,ll>>> G;

vector<vector<ll>> compute_distance() {
    vector<vector<vector<ll>>> d(N+1, vector<vector<ll>>(N, vector<ll>(N, INF)));
    for (int u = 0; u < N; u++) {
        d[0][u][u] = 0;
        for (auto &e : G[u]) {
            d[0][u][e.first] = e.second;
        }
    }
    for (int i = 0; i < N; i++) {
        d[i+1] = d[i];
        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                d[i+1][s][t] = min(d[i+1][s][t], d[i][s][i] + d[i][i][t]);
            }
        }
    }
    return d[N];
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(make_pair(v, w));
    }

    vector<vector<ll>> d = compute_distance();
    vector<vector<ll>> dp((1 << N), vector<ll>(N, INF));
    for (int u = 0; u < N; u++) dp[(1 << u)][u] = 0;

    for (int s = 0; s < (1 << N); s++) {
        for (int u = 0; u < N; u++) {
            if (dp[s][u] >= INF/2) continue;
            for (int v = 0; v < N; v++) {
                dp[s | (1 << v)][v] = min(dp[s | (1 << v)][v], dp[s][u] + d[u][v]);
            }
        }
    }

    ll ans = INF;
    for (int u = 0; u < N; u++) ans = min(ans, dp[(1 << N)-1][u]);
    if (ans >= INF/2) cout << "No\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
