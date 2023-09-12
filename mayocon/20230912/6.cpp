// https://atcoder.jp/contests/abc191/tasks/abc191_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    double d;
    cin >> d;
    ll X = round(d * 1e+4);
    cin >> d;
    ll Y = round(d * 1e+4);
    cin >> d;
    ll R = round(d * 1e+4);

    ll y = Y;
    while (y % 10000 != 0) y++;

    ll ans = 0;

    while ((Y - y)*(Y-y) <= R*R) {
        ll l = 0, r = 2e+9;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll d2 = (Y - y)*(Y - y) + m*m;
            if (d2 <= R*R) l = m;
            else r = m;
        }
        ll right = X + l;
        if (right % 10000 != 0) {
            if (right > 0) right = right - (right % 10000);
            else right = right - (right % 10000) - 10000;
        }
        ll left = X - l - 1;
        if (left % 10000 != 0) {
            if (left > 0) left = left - (left % 10000);
            else left = left - (left % 10000) - 10000;
        }

        ans += (right - left) / 10000;
        y += 10000;
    }

    y = Y - 1;
    while (y % 10000 != 0) y--;
    while ((Y - y)*(Y-y) <= R*R) {
        ll l = 0, r = 2e+9;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll d2 = (Y - y)*(Y-y) + m*m;
            if (d2 <= R*R) l = m;
            else r = m;
        }
        ll right = X + l;
        if (right % 10000 != 0) {
            if (right > 0) right = right - (right % 10000);
            else right = right - (right % 10000) - 10000;
        }
        ll left = X - l - 1;
        if (left % 10000 != 0) {
            if (left > 0) left = left - (left % 10000);
            else left = left - (left % 10000) - 10000;
        }

        ans += (right - left) / 10000;
        y -= 10000;
    }

    cout << ans << endl;
}
