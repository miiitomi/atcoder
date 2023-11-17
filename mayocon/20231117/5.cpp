// https://atcoder.jp/contests/abc307/tasks/abc307_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i-1][0]*(M-1)%MOD) % MOD;
        dp[i][1] = (dp[i][1] + dp[i-1][1]*(M-2)%MOD) % MOD;
    }

    ll ans = dp[N-1][1] * M % MOD;
    cout << ans << endl;
}
