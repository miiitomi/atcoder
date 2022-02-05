#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

ll _pow(ll a, ll k) {
    if (k == 0) return 1;
    ll out = 1;
    if (k % 2) {
        out = a;
    }
    ll p = _pow(a, k/2);
    return (out * p % MOD) * p % MOD;
}

int main() {
    ll N;
    cin >> N;
    ll k = (to_string(N)).size();
    ll ans = 0;
    ll p = _pow(2, MOD - 2);

    for (ll i = 1; i < k; i++) {
        ll left = 1;
        ll right;
        if (i == 1) right = 9;
        else right = (_pow(10LL, i) - _pow(10LL, i-1));
        ll a = ((((left + right) % MOD) * ((right - left + 1) % MOD) % MOD) * p) % MOD;
        ans = (ans + a) % MOD;
    }

    ll left = 1;
    ll right;
    if (k == 1) right = N;
    else right = N + 1 - _pow(10LL, k-1);
    ll a = ((((left + right) % MOD) * ((right - left + 1) % MOD) % MOD) * p) % MOD;
    ans = (ans + a) % MOD;

    cout << ans << endl;
}
