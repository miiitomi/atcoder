#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> pair<T, T> ext_gcd(T a, T b) {
    // a*x + b*y = gcd(a, b) となるような整数の組 (x, y) を返す.
    if (b == 0) return make_pair(1, 0);
    T x, y;
    tie(y, x) = ext_gcd(b, a % b);
    y -= a / b * x;
    return make_pair(x, y);
}

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == 0) {
        if (abs(y) == 1) cout << 2 << " " << 0 << endl;
        else if (abs(y) == 2) cout << 1 << " " << 0 << endl;
        else cout << -1 << endl;
        return;
    }
    if (y == 0) {
        if (abs(x) == 1) cout << 0 << " " << 2 << endl;
        else if (abs(x) == 2) cout << 0 << " " << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    ll g = gcd(abs(x), abs(y));
    if (g >= 3) {
        cout << -1 << endl;
        return;
    }
    pair<ll, ll> res = ext_gcd(x, -y);
    if (g == 1) {
        res.first *= 2;
        res.second *= 2;
    }
    cout << res.second << " " << res.first << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
