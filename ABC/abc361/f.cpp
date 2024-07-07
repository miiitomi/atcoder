#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll sqrt_lower(ll X) {
    ll left = 0, right = (ll)1e+9 + 1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        if (m*m > X) right = m;
        else left = m;
    }
    return left;
}

void solve() {
    ll N;
    cin >> N;
    if (N <= 3) {
        cout << 1 << endl;
        return;
    }
    ll ans = sqrt_lower(N);
    vector<ll> v;
    for (ll a = 2; a <= 1e+6; a++) {
        for (ll b = 3; ; b++) {
            __int128_t x = 1;
            bool is_ok = true;
            for (ll k = 0; k < b; k++) {
                x *= (__int128_t)a;
                if (x > N) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) v.push_back((ll)x);
            else break;;
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ans += v.size();
    for (ll x : v) {
        ll y = sqrt_lower(x);
        if (y*y == x) ans--;
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
