// https://atcoder.jp/contests/abc048/tasks/abc048_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll f(ll R, ll x) {
    if (R < 0) return 0;
    return R/x + 1;
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    cout << f(b, x) - f(a-1, x) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
