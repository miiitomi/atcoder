#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(N, vector<ll>(9, 1));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % MOD;
            } else if (j == 8) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 9; i++) {
        ans += dp[N-1][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
