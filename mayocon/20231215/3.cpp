// https://atcoder.jp/contests/abc178/tasks/abc178_c
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
    ll N;
    cin >> N;

    ll ans = mod_pow(10, N);
    ans = (ans - mod_pow(9, N) + MOD) % MOD;
    ans = (ans - mod_pow(9, N) + MOD) % MOD;
    ans = (ans + mod_pow(8, N)) % MOD;

    cout << ans << endl;
}
