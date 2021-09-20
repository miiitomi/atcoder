#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;

ll _pow(ll x, ll n) {
    if (n == 0LL) return 1LL;
    ll res = _pow(x * x % MOD, n / 2LL);
    if (n % 2LL == 1LL) res = res * x % MOD;
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = K;
    if (N == 1) {
        cout << ans << endl;
        return 0;
    }
    ans = ans * (K - 1LL) % MOD;
    ans = ans * _pow(K - 2LL, N - 2LL) % MOD;
    cout << ans << endl;
}
