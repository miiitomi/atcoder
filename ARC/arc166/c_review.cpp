#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

vector<ll> a, b;

int main() {
    a.assign(2e+6+2, 1);
    for (int i = 2; i < (int)a.size(); i++) a[i] = (a[i-1] + a[i-2]) % MOD;
    b.assign(1e+6+1, 1);
    for (int i = 1; i <= 1e+6; i++) b[i] = (b[i-1] * a[2*i]) % MOD;
    for (int i = 1; i <= 1e+6; i++) b[i] = (b[i] * b[i]) % MOD;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int H, W;
        cin >> H >> W;
        if (H > W) swap(H, W);

        ll ans = b[H] * mod_pow(a[2*H+1], W-H) % MOD;
        cout << ans << endl;
    }
}
