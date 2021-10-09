#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll modpow(ll x, ll n) {
    if (n == 0) return 1LL;
    else {
        ll res = modpow(x, n/2);
        res = res * res % MOD;
        if (n % 2 == 1) res = res * x % MOD;
        return res;
    }
}

int main() {
    ll N, D;
    cin >> N >> D;
    ll ans = 0;

    for (int v = 1; v <= N; v++) {
        ll tmp = 0LL;
        if (D <= N - v) {
            tmp += modpow(2, D+1);
            tmp += (D-1) * modpow(2, D-1) % MOD;
            tmp %= MOD;
        } else if (D <= 2 * (N-v)) {
            tmp += (N-v - (D-N+v) + 1) * modpow(2, D-1) % MOD;
        }
        ans += tmp * modpow(2, v-1);
        ans %= MOD;
    }
    cout << ans << endl;
}
