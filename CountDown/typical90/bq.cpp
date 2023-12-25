#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

ll mod_pow(ll a, ll n) {
    if (a == 0) return 0;
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    ll N, K;
    cin >> N >> K;

    if (N == 1) cout << K << endl;
    else if (N == 2) cout << K * (K-1) % MOD << endl;
    else cout << K * (K-1) % MOD * mod_pow(K-2, N-2) % MOD << endl;
}
