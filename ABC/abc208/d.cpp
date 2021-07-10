#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N, vector<int>(N, 1e9)));
    for (int i = 0; i < N; i++) {
        dp[0][i][i] = 0;
    }
    for (int m = 0; m < M; m++) {
        dp[0][A[m]-1][B[m]-1] = C[m];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j][i-1] + dp[i-1][i-1][k]);
            }
        }
    }

    int64_t ans = 0LL;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (dp[i][j][k] < 1e9) ans += dp[i][j][k];
            }
        }
    }

    cout << ans << endl;
}
