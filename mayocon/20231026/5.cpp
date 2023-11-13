// https://atcoder.jp/contests/abc228/tasks/abc228_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    else return res * res % mod;
}

int main() {
    ll N, K, M;
    cin >> N >> K >> M;
    K %= MOD-1;
    M %= MOD;

    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll r = mod_pow(K, N, MOD-1);
    ll ans = mod_pow(M, r, MOD);

    cout << ans << endl;
}
