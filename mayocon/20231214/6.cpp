// https://atcoder.jp/contests/abc159/tasks/abc159_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, S;
    cin >> N >> S;

    ll ans = 0;
    vector<ll> dp(S+1, 0), sum(S+1, 0);
    dp[0] = 1;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        for (int j = S; j - a >= 0; j--) dp[j] = (dp[j] + dp[j-a]) % MOD;
        for (int j = 0; j <= S; j++) sum[j] = (sum[j] + dp[j]) % MOD;
    }

    for (int i = 0; i < N; i++) {
        ans = (ans + sum[S]) % MOD;
        ll a = A[i];
        for (int j = a; j <= S; j++) {
            sum[j] = (sum[j] - sum[j-a] + MOD) % MOD;
        }
        sum[0]--;
    }
    cout << ans << endl;
}
