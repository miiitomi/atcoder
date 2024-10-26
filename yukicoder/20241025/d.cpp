#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> X(K);
    for (int i = 0; i < K; i++) {
        cin >> X[i];
        X[i]--;
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<int>> dp(N, vector<int>(1 << N, 0));
    for (int i = 0; i < K; i++) dp[X[i]][1 << X[i]] |= (1 << i);
    vector<vector<int>> ans(N, vector<int>(N+1, 0));
    for (int s = 0; s < (1 << N); s++) {
        for (int u = 0; u < N; u++) {
            if (!(s & (1 << u)) || dp[u][s] == 0) continue;
            int cnt = 0;
            for (int v = 0; v < N; v++) if (s & (1 << v)) cnt++;
            ans[u][cnt] |= dp[u][s];
            for (int v : G[u]) {
                if (s & (1 << v)) continue;
                dp[v][s | (1 << v)] |= dp[u][s];
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int u = 0; u < N; u++) {
            if (ans[u][k] == ((1 << K) - 1)) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
