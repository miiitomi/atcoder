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

int main() {
    ll N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    ll ans = 0;
    for (int s = 1; s < (1 << N); s++) {
        vector<ll> used(26, 0);
        int k = 0;
        for (int i = 0; i < N; i++) {
            if (s & (1 << i)) {
                for (char c : S[i]) used[(int)(c-'a')]++;
                k++;
            }
        }
        int a = 0;
        for (int i = 0; i < 26; i++) a += (used[i] == k);
        if (a > 0) {
            if (k % 2 == 1) ans = (ans + mod_pow(a, L)) % MOD;
            else ans = (ans - mod_pow(a, L) + MOD) % MOD;
        }
    }

    cout << ans << endl;
}
