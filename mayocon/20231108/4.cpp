// https://atcoder.jp/contests/abc156/tasks/abc156_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll MOD = 1e+9 + 7;
using mint = modint1000000007;

mint c(ll n, ll r) {
    if (r == 0) return 1;
    return c(n-1, r-1) * n / r;
}

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;

    mint ans = mod_pow(2LL, N);
    ans -= 1;
    ans -= c(N, A);
    ans -= c(N, B);

    cout << ans.val() << endl;
}
