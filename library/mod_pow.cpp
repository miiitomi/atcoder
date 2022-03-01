// https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll a, ll n, ll MOD) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2, MOD);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    ll a, n;
    cin >> a >> n;
    ll MOD = 1000000007;

    cout << mod_pow(a, n, MOD) << endl;
}
