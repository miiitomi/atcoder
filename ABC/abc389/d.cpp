#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll R;

bool f(ll x, ll y) {
    return x*x + y*y <= R*R;
}

bool is_in(ll lx, ll rx, ll ly, ll ry) {
    return f(lx, ly) && f(lx, ry) && f(rx, ly) && f(rx, ry);
}

void solve() {
    cin >> R;
    R *= 2;
    ll ans = 0;
    for (ll y = -R-1; y <= R+1; y += 2) {
        ll left = 0, right = 4*R;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            ll cx = (m-1)*2;
            ll lx = cx-1, rx = cx+1, ly = y, ry = y+2;
            if (is_in(lx, rx, ly, ry)) left = m;
            else right = m;
        }
        if (left > 0) {
            ans += 2*left - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
