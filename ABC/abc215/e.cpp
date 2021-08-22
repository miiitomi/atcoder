#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<vector<int64_t>>> dp(N+1, vector<vector<int64_t>>((1 << 10), vector<int64_t>(11, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        int x = (int)(S[i] - 'A' + 1);
        for (int U = 0; U < (1 << 10); U++) {
            for (int j = 0; j < 11; j++) {
                if (j != x) {
                    dp[i+1][U][j] = dp[i][U][j];
                } else if (U & (1 << x-1)) {
                    dp[i+1][U][x] += 2 * dp[i][U][x];
                    int U_prime = U - (1 << x-1);
                    for (int k = 0; k < 11; k++) dp[i+1][U][x] += dp[i][U_prime][k];
                }
                dp[i+1][U][j] %= MOD;
            }
        }
    }

    int64_t ans = 0;
    for (int U = 0; U < (1 << 10); U++) {
        for (int j = 0; j < 11; j++) {
            ans += dp[N][U][j];
            ans %= MOD;
        }
    }
    ans--;
    cout << ans << endl;
}
