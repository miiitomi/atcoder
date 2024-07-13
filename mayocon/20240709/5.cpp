// https://atcoder.jp/contests/abc228/tasks/abc228_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> T mod_pow(T a, ll n, ll mod) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    return res * res % mod;
}

void solve() {
    ll N, K, M;
    cin >> N >> K >> M;
    M %= MOD;
    if (M == 0) {
        cout << 0 << endl;
        return;
    }
    ll x = mod_pow(K%(MOD-1), N, MOD-1);
    ll ans = mod_pow(M, x, MOD);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
