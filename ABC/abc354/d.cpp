#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x, ll y) {
    ll ans = 0;
    ll r = x/4;
    ans += 2 * ((r * (y / 2) * 4) + (r * (y % 2) * 2));
    x %= 4;
    if (x == 1) {
        ans += (y/2) * 3 + (y%2) * 2;
    } else if (x == 2) {
        ans += (y/2) * 6 + (y % 2) * 3;
    } else if (x == 3) {
        ans += (y/2) * 7 + (y%2) * 3;
    }
    return ans;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < 0) {
        ll x = -a;
        while (x % 4 != 0) x++;
        a += x;
        c += x;
    }
    if (b < 0) {
        ll x = -b;
        while (x % 4 != 0) x++;
        b += x;
        d += x;
    }

    ll ans = 0;
    ans += f(c, d);
    ans += f(a, b);
    ans -= f(c, b);
    ans -= f(a, d);

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
