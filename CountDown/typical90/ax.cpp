#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e+9 + 7;

int main() {
    ll N, L;
    cin >> N >> L;

    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        dp[i+1] = (dp[i+1] + dp[i]) % MOD;
        if (i + L <= N) dp[i+L] = (dp[i+L] + dp[i]) % MOD;
    }

    cout << dp[N] << endl;
}
