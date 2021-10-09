#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    vector<vector<ll>> dp(N, vector<ll>(3001, 0));
    for (int i = a[0]; i <= b[0]; i++) {
        dp[0][i]++;
    }
    for (int i = 1; i < N; i++) {
        for (int k = 0; k <= 3000; k++) {
                int s = max(k, a[i]);
                int t = max(k, b[i]);
                dp[i][s] += dp[i-1][k];
                dp[i][s] %= MOD;
                if (t < 3000) dp[i][t+1] -= dp[i-1][k];
        }
        dp[i][0] %= MOD;
        for (int k = 1; k <= 3000; k++) {
            dp[i][k] += dp[i][k-1];
            dp[i][k] %= MOD;
        }
    }
    ll ans = 0;
    for (int k = 0; k <= 3000; k++) {
        ans = (ans + dp[N-1][k]) % MOD;
    }
    cout << ans << endl;
}
