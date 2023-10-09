#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll x, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(x, n/2);
    if (n % 2 == 1) return res * res % MOD * x % MOD;
    else return res * res % MOD;
}

vector<ll> a;
vector<ll> b;

void preprocessing() {
    a.assign(2e+6+2, 0);
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= 2e+6 + 1; i++) a[i] = (a[i-2] + a[i-1]) % MOD;

    b.assign(1e+6+1, 1);
    for (int i = 1; i <= 1e+6; i++) b[i] = b[i-1]*a[2*i]%MOD;
    for (int i = 1; i <= 1e+6; i++) b[i] = (b[i]*b[i])%MOD;
}

void solve() {
    int H, W;
    cin >> H >> W;
    if (H > W) swap(H, W);

    ll ans = 1;
    ans = ans * b[H] % MOD;
    ans = ans * mod_pow(a[2*H+1], W-H) % MOD;

    cout << ans << endl;
    return;
}

int main() {
    preprocessing();
    
    int T;
    cin >> T;
    for (int q = 0; q < T; q++) solve();
}
