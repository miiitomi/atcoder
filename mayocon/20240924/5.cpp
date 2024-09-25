// https://atcoder.jp/contests/abc340/tasks/abc340_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

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
        if (y >= 3) cout << -1 << endl;
        else cout << 2/y << " " << 0 << endl;
        return;
    }
    if (y == 0) {
        if (x >= 3) cout << -1 << endl;
        else cout << 0 << " " << 2/x << endl;
        return;
    }
    ll c = gcd(x, y);
    if (c >= 3) {
        cout << -1 << endl;
        return;
    }
    auto res = ext_gcd(x, -y);
    swap(res.first, res.second);
    if (c == 1) {
        res.first *= 2;
        res.second *= 2;
    }
    cout << res.first << " " << res.second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
