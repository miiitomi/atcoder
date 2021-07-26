#include <bits/stdc++.h>
using namespace std;
const int MOD = pow(10, 9) + 7;

int main() {
    string S;
    cin >> S;
    string C = "chokudai";
    int N = (int)S.size();
    vector<vector<int64_t>> dp(8, vector<int64_t>(N, 0LL));

    if (S[N-1] == 'i') dp[7][N-1] = 1LL;
    for (int i = N - 2; i >= 0; i--) {
        if (S[i] == 'i') {
            dp[7][i] = dp[7][i+1] + 1LL;
        } else {
            dp[7][i] = dp[7][i+1];
        }
    }

    for (int j = 6; j >= 0; j--) {
        for (int i = N - 2; i >= 0; i--) {
            if (S[i] != C[j]) {
                dp[j][i] = dp[j][i+1];
            } else {
                dp[j][i] = (dp[j][i+1] + dp[j+1][i+1]) % MOD;
            }
        }
    }

    cout << dp[0][0] << endl;
}
