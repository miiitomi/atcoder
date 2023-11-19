#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    if (S[0] != T[0]) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<bool>> dp(N, vector<bool>(M, false));
    dp[0][0] = true;
    for (int i = 1; i < N; i++) {
        for (int j = max(1, i+M-N); j <= min(M-1, i); j++) {
            if (dp[i-1][j-1] && S[i] == T[j]) dp[i][j] = true;
        }

        if (dp[i-1][M-1]) {
            for (int j = max(0, i+M-N); j <= min(i, M-1); j++) {
                if (S[i] == T[j]) dp[i][j] = true;
            }
        }

        bool ok = false;
        for (int j = 0; j < M; j++) if (dp[i-1][j]) ok = true;
        if (ok && S[i] == T[0]) dp[i][0] = true;
    }

    if (dp[N-1][M-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
