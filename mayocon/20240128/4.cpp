// https://atcoder.jp/contests/abc048/tasks/abc048_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_l(ll x, ll a) {
    // a 以上の最小の x の倍数
    ll left = 0, right = (ll)4e+18 / x;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (mid * x >= a) right = mid;
        else left = mid;
    }
    return (left+1) * x;
}

ll find_r(ll x, ll b) {
    // b 以下の最大の x の倍数
    ll left = 0, right = (ll)4e+18 / x;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (mid * x > b) right = mid;
        else left = mid;
    }
    return left * x;
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    ll l = find_l(x, a) / x, r = find_r(x, b) / x;
    if (a == 0) l = 0;
    if (b == 0) r = 0;

    if (r < l) cout << 0 << endl;
    else cout << r - l + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
