// https://atcoder.jp/contests/abc191/tasks/abc191_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll X, Y, R;

ll distance(ll x, ll y) {return (x - X)*(x - X) + (y - Y)*(y - Y);}

void solve() {
    double _x, _y, _r;
    cin >> _x >> _y >> _r;
    X = round(_x * 10000);
    Y = round(_y * 10000);
    R = round(_r * 10000);
    ll ans = 0;
    for (ll y = (ll)2e+9; y >= -(ll)2e+9; y -= 10000) {
        if (distance(X, y) > R*R) continue;
        ll l1 = X, r1 = (ll)2e+9 + 1;
        while (r1 - l1 > 1) {
            ll m = (r1 + l1) / 2;
            if (distance(m, y) > R*R) r1 = m;
            else l1 = m;
        }

        ll l2 = -(ll)2e+9 - 1, r2 = X;
        while (r2 - l2 > 1) {
            ll m = (r2 + l2) / 2;
            if (distance(m, y) > R*R) l2 = m;
            else r2 = m;
        }

        if (l1 % 10000LL != 0) {
            if (l1 > 0) l1 -= (l1 % 10000LL);
            else l1 -= (10000 + l1%10000LL);
        }
        if (r2 % 10000LL != 0) {
            if (r2 > 0) r2 += (10000 - r2 % 10000LL);
            else r2 -= r2 % 10000LL;
        }

        if (r2 <= l1) ans += 1 + (l1 - r2) / 10000;
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
