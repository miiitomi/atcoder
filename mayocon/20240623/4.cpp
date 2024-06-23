// https://atcoder.jp/contests/abc246/tasks/abc246_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    ll ans = 1e+18;
    for (ll a = 0; a <= 1e+6; a++) {
        ll l = -1, r = (ll)(1e+6) + 1;
        while (r - l > 1) {
            ll b = (l + r)/2;
            ll X = a*a*a + a*a*b + a*b*b + b*b*b;
            if (X >= N) r = b;
            else l = b;
        }
        ll b = r;
        ll X = a*a*a + a*a*b + a*b*b + b*b*b;
        ans = min(ans, X);
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
