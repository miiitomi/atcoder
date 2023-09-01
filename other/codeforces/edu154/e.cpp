#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;

vector<vector<vector<ll>>> dp;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<ll>> dp(K, vector<ll>(1+N/K, 0));
    dp[1][0] = K;

    for (int i = 0; i < N-1; i++) {
        vector<vector<ll>> dp_new(K, vector<ll>(1+N/K, 0));
        for (int c = 0; c <= N/K; c++) {
            ll sum = 0;
            for (int j = 0; j < K; j++) {
                if (dp[j][c] != 0) {
                    if (j < K-1) {
                        dp_new[j+1][c] = (dp_new[j+1][c] + (K - j) * dp[j][c] % MOD) % MOD;
                    } else {
                        dp_new[0][c+1] = (dp_new[0][c+1] + dp[j][c]) % MOD;
                    }
                }
                sum = (sum + dp[K-1-j][c]) % MOD;
                if (j != K-1) dp_new[K-1-j][c] = (dp_new[K-1-j][c] + sum) % MOD;
            }
        }
        dp = dp_new;
    }

    ll ans = 0;
    for (int j = 0; j < K; j++) {
        for (int c = 0; c <= N/K; c++) ans = (ans + c*dp[j][c] % MOD) % MOD;
    }
    cout << ans << endl;
}
