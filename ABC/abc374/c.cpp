#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> K(N);
    for (ll &x : K) cin >> x;
    ll ans = INF;
    for (ll s = 0; s < (1 << N); s++) {
        ll a = 0, b = 0;
        for (ll i = 0; i < N; i++) {
            if (s & (1 << i)) a += K[i];
            else b += K[i];
        }
        ll tmp = max(a, b);
        ans = min(ans, tmp);
    }
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