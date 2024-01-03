#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll base = 101, MOD = 1e+9 + 9;
ll N;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = MOD, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res % MOD * a % MOD;
    else return res * res % MOD;
}

ll P = mod_pow(10LL, N-1);

ll f(string &S) {
    ll x = 0;
    for (int i = 0; i < N; i++) {
        x = ((x * base) + ((int)S[i] - 'a' + 1)) % MOD;
    }

    set<ll> st;
    st.insert(x);
    for (int i = 0; i < N; i++) {
        x = ((x - (P*((int)S[i] - 'a' + 1)%MOD) + MOD) % MOD * base + ((int)S[i] - 'a' + 1)) % MOD;
        st.insert(x);
    }

    return st.size();
}

int main() {
    cin >> N;
}
