#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string atcoder = "atcoder";

    vector<vector<int>> dp(N, vector<int>(7, 0));
    if (S[0] == 'a') dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0) {
                dp[i][j] = (dp[i-1][j] + (S[i] == atcoder[j])) % MOD;
            } else {
                dp[i][j] = dp[i-1][j];
                if (S[i] == atcoder[j]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
            }
        }
    }
    cout << dp[N-1][6] << endl;
}
