// https://atcoder.jp/contests/abc185/tasks/abc185_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;


void solve() {
    ll L;
    cin >> L;
    L--;
    ll ans = 1;
    for (ll r = 0; r < 11; r++) {
        ans *= L-r;
        ans /= (r+1);
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
