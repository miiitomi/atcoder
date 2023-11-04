#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> P;

int main() {
    cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    vector<vector<double>> dp(N, vector<double>(N+1, -1));
    for (int i = 0; i < N; i++) dp[i][0] = 0;
    dp[0][1] = P[0];

    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i-1][j-1] < 0) break;
            dp[i][j] = max(dp[i-1][j], 0.9*dp[i-1][j-1] + P[i]);
        }
    }

    double ans = dp[N-1][1] - 1200;
    double d = 1.0, s = 1;
    for (int k = 2; k <= N; k++) {
        s *= 0.9;
        d += s;
        ans = max(ans, dp[N-1][k] / d - (1200.0 / sqrt((double)k)));
    }
    cout << fixed << setprecision(15) << ans << endl;
}
