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

    if (M % MOD == 0) {
        cout << 0 << endl;
        return 0;
    }
    M %= MOD;

    ll b;
    K %= MOD-1;
    if (K == 0) b = 0;
    else b = mod_pow(K, N, MOD-1);

    cout << mod_pow(M, b, MOD) << endl;
}
