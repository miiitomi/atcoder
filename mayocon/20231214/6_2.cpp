#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> dp(S+1, 0), sum(S+1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = S; j >= 0; j--) {
            if (j - A[i] >= 0) dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
            sum[j] = (sum[j] + dp[j]) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + sum[S]) % MOD;
        for (int j = A[i]; j <= S; j++) {
            sum[j] = (sum[j] - sum[j - A[i]] + MOD) % MOD;
        }
        sum[0] = (sum[0] - 1 + MOD) % MOD;
    }

    cout << ans << endl;
}
