// https://atcoder.jp/contests/abc249/tasks/abc249_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, MOD;

int main() {
    cin >> N >> MOD;
    vector<vector<ll>> dp(1+N, vector<ll>(1+N, 0));
    dp[0][0] = 1;
    dp[1][0] = -1;
    for (int j = 0; j <= N; j++) {
        for (int i = 0; i < N; i++) dp[i+1][j] = (dp[i+1][j] + dp[i][j] + MOD) % MOD;
        if (j == N) break;
        for (int i = 0; i < N; i++) {
            ll x = 25 * dp[i][j] % MOD;
            if (i == 0 && j == 0) x = 26;
            if (i+1 <= N && j + 2 <= N) {
                dp[i+1][j+1+1] = (dp[i+1][j+1+1] + x) % MOD;
                if (i + 10 <= N) dp[i+10][j+1+1] = (dp[i+10][j+1+1] - x + MOD) % MOD;
            }
            if (i + 10 <= N && j + 3 <= N) {
                dp[i + 10][j + 1 + 2] = (dp[i + 10][j + 1 + 2] + x) % MOD;
                if (i + 100 <= N) dp[i + 100][j + 1 + 2] = (dp[i + 100][j + 1 + 2] - x + MOD) % MOD;
            }
            if (i + 100 <= N && j + 4 <= N) {
                dp[i + 100][j + 1 + 3] = (dp[i + 100][j + 1 + 3] + x) % MOD;
                if (i + 1000 <= N) dp[i + 1000][j + 1 + 3] = (dp[i + 1000][j + 1 + 3] - x + MOD) % MOD;
            }
            if (i + 1000 <= N && j + 5 <= N) {
                dp[i + 1000][j + 5] = (dp[i + 1000][j + 5] + x) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int t = 0; t < N; t++) ans = (ans + dp[N][t]) % MOD;
    cout << ans << endl;
}
