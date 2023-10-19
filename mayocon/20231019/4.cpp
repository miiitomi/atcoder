// https://atcoder.jp/contests/abc253/tasks/abc253_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N, vector<ll>(M, 0));
    for (int j = 0; j < M; j++) dp[0][j] = 1;

    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            if (K == 0) {
                dp[i+1][0] = (dp[i+1][0] + dp[i][j]) % MOD;
            } else {
                if (j - K >= 0) {
                    dp[i+1][0] = (dp[i+1][0] + dp[i][j]) % MOD;
                    dp[i+1][j-K+1] = (dp[i+1][j-K+1] - dp[i][j] + MOD) % MOD; 
                }
                if (j + K < M) dp[i+1][j+K] = (dp[i+1][j+K] + dp[i][j]) % MOD;
            }
        }
        for (int j = 0; j < M-1; j++) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i+1][j]) % MOD;
    }

    ll ans = 0;
    for (int j = 0; j < M; j++) ans = (ans + dp[N-1][j]) % MOD;
    cout << ans << endl;
}
