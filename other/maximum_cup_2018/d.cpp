#include <bits/stdc++.h>
using namespace std;

int INF = 100000000;

int main() {
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<int>> dp(N+1, vector<int>(M, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i+1][j] = dp[i][j];
            if (j - a[i] >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-a[i]]);
            else dp[i+1][j] = min(dp[i+1][j], dp[i][((j-a[i])%M)+M] - ((j-a[i])/M) + 1);
        }
    }

    if (dp[N][L] < X) cout << "Yes" << endl;
    else cout << "No" << endl;
}
