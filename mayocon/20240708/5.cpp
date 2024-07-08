// https://atcoder.jp/contests/abc354/tasks/abc354_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll f(ll X, ll Y) {
    ll x = X/4, y = Y/2;
    ll ans = y*8*x;
    if (Y%2 == 1) ans += 4*x;

    if (X%4==1) {
        ans += 3*y;
        if (Y%2 == 1) ans += 2;
    } else if (X%4 == 2) {
        ans += 6*y;
        if (Y%2 == 1) ans += 3;
    } else if (X % 4 == 3) {
        ans += 7*y;
        if (Y%2 == 1) ans += 3;
    }
    return ans;
}

void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll tmp = (ll)1e+9;
    A += tmp; B += tmp; C += tmp; D += tmp;
    ll ans = f(C, D) - f(A, D) - f(C, B) + f(A, B);
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
