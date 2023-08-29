#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e+9) + 7LL;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    string L;
    cin >> L;
    int N = (int)L.size();

    vector<ll> dp(N+1, 1);
    for (int i = 1; i <= N; i++) {
        if (L[N-i] == '1') {
            dp[i] = ((2*dp[i-1]) % MOD + mod_pow(3, i-1)) % MOD;
        }
        else dp[i] = dp[i-1];
    }

    ll ans = (2*dp[N-1]) % MOD;
    ans = (ans + mod_pow(3, N-1)) % MOD;
    cout << ans << endl;
}
