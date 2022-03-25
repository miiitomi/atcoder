#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e+18;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    vector<vector<ll>> cost(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            cost[i][j] = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0LL, Z[j] - Z[i]);
        }
    }

    const ll S = (1 << N);
    vector<vector<ll>> dp(S, vector<ll>(N, INF));
    for (int u = 1; u < N; u++) {
        dp[(1 << u)][u] = cost[0][u];
    }

    for (int s = 0; s < S; s++) {
        for (int u = 0; u < N; u++) {
            if (((s >> u) & 1) == 0) continue;
            for (int v = 0; v < N; v++) {
                if ((s >> v) & 1) continue;
                dp[s + (1 << v)][v] = min(dp[s + (1 << v)][v], dp[s][u] + cost[u][v]);
            }
        }
    }

    cout << dp[S-1][0] << endl;
}
