// https://atcoder.jp/contests/abc162/tasks/abc162_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    ll N, K, ans=0;
    cin >> N >> K;
    vector<ll> dp(K+1, 0);

    for (int x = K; x >= 1; x--) {
        dp[x] = mod_pow(K / x, N);
        for (int y = 2*x; y <= K; y += x) {
            dp[x] = (dp[x] - dp[y] + MOD) % MOD;
        }
        ans = (ans + x*dp[x]%MOD) % MOD;
    }
    cout << ans << endl;
}
