#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    N *= 2;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(N, vector<int>(N, 1e+9));
    for (int i = 0; i < N-1; i++) {
        dp[i][i+1] = abs(A[i]-A[i+1]);
    }
    for (int k = 3; k <= N-1; k += 2) {
        for (int i = 0; i + k <= N-1; i++) {
            dp[i][i+k] = abs(A[i] - A[i+k]) + dp[i+1][i+k-1];
            for (int j = i+1; j < i+k; j += 2) {
                dp[i][i+k] = min(dp[i][i+k], dp[i][j]+dp[j+1][i+k]);
            }
        }
    }

    cout << dp[0][N-1] << endl;
}
