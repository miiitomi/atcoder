// https://atcoder.jp/contests/abc130/tasks/abc130_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    double ans = (W*H)/2.0;
    bool b = (W%2 == 0 && x == W/2 && H%2 == 0 && y == H/2);
    cout << ans << " ";
    if (b) cout << "1\n";
    else cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
