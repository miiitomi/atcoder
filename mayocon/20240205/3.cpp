// https://atcoder.jp/contests/abc330/tasks/abc330_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll D;
    cin >> D;
    ll ans = 1e+18;

    for (ll y = 0; y <= (ll)2e+6; y++) {
        ll T = D - y*y;
        ll l = 0, r = 1e+7;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (m*m > T) r = m;
            else l = m;
        }
        ans = min(ans, abs(l*l + y*y - D));
        ans = min(ans, abs(r*r + y*y - D));
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
