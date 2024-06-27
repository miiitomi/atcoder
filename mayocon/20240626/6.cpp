// https://atcoder.jp/contests/abc191/tasks/abc191_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll X, Y, RR;
void get_input() {
    double x, y, r;
    cin >> x >> y >> r;
    X = round(x * 10000);
    Y = round(y * 10000);
    RR = round(r * 10000);
}

void solve() {
    get_input();
    ll y = Y+RR;
    if (y % 10000 != 0) {
        if (y > 0) y -= (y%10000);
        else y -= 10000 - (-y)%10000;
    }

    ll ans = 0;

    for (; y >= Y-RR; y -= 10000) {
        ll L, R;
        ll l = X, r = X + (ll)(1e+9) + 1;
        while (r-l > 1) {
            ll m = (l+r)/2;
            if ((m-X)*(m-X)+(y-Y)*(y-Y) <= RR*RR) l = m;
            else r = m;
        }
        R = l;
        if (R % 10000 != 0) {
            if (R > 0) R -= (R%10000);
            else R -= 10000 - (-R)%10000;
        }

        l = X - (ll)(1e+9) - 1, r = X;
        while (r - l > 1) {
            ll m = (l+r) / 2;
            if ((m-X)*(m-X)+(y-Y)*(y-Y) <= RR*RR) r = m;
            else l = m;
        }
        L = l;
        if (L % 10000 != 0) {
            if (L > 0) L -= (L%10000);
            else L -= 10000 - (-L)%10000;
        }

        ans += (R - L) / 10000;
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
