#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint1000000007;

ll N, B, K;
vector<ll> c;
unordered_map<ll, vector<mint>> M;
unordered_map<ll, ll> ten_pow_map;

ll mod_pow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    else return res * res % mod;
}

ll ten_pow(ll n) {
    if (ten_pow_map.count(n)) return ten_pow_map[n];
    else {
        ten_pow_map[n] = mod_pow(10, n, B);
        return ten_pow_map[n];
    }
}

vector<mint> rec(ll n) {
    if (M.count(n)) return M[n];

    ll i = 1;
    while (2*i < n) i *= 2;
    ll j = n - i;

    vector<mint> x = rec(i);
    vector<mint> y = rec(j);
    vector<mint> z(B, 0);

    for (ll p = 0; p < B; p++) {
        for (ll q = 0; q < B; q++) {
            ll s = (p*ten_pow(j) + q) % B;
            z[s] += x[p] * y[q];
        }
    }
    M[n] = z;
    return z;
}

int main() {
    cin >> N >> B >> K;
    c.resize(K);
    for (int i = 0; i < K; i++) cin >> c[i];

    vector<mint> x(B, 0);
    x[0] = 1;
    M[0] = x;

    x[0] = 0;
    for (int i = 0; i < K; i++) x[c[i]%B]++;
    M[1] = x;

    vector<mint> y = rec(N);
    cout << y[0].val() << endl;
}
