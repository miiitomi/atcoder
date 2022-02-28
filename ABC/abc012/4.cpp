#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        dp[a][b] = t;
        dp[b][a] = t;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    cout << ans << endl;
}
