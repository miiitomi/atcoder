// https://atcoder.jp/contests/typical90/tasks/typical90_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, B, K;
vector<ll> c;
vector<mint> v;

ll mod_pow(ll a, ll n, ll mod) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res * a % mod;
    return res * res % mod;
}

vector<mint> f(ll n) {
    if (n == 1) return v;
    ll m = n/2, p = mod_pow(10%B, m, B);
    vector<mint> w = f(m), a(B, 0);
    for (ll i = 0; i < B; i++) {
        for (ll j = 0; j < B; j++) {
            a[(i*p + j)%B] += w[i] * w[j];
        }
    }
    if (!(n & 1)) return a;
    w.assign(B, 0);
    for (ll i = 0; i < B; i++) {
        for (ll j = 0; j < B; j++) {
            w[(i*10 + j)%B] += a[i] * v[j];
        }
    }
    return w;
}

void solve() {
    cin >> N >> B >> K;
    c.resize(K);
    v.assign(B, 0);
    for (int k = 0; k < K; k++) {
        cin >> c[k];
        v[c[k] % B] += 1;
    }
    vector<mint> a = f(N);
    cout << a[0].val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
