// https://atcoder.jp/contests/abc330/tasks/abc330_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll D;
    cin >> D;
    vector<ll> v;
    for (ll y = 0; y <= 1e+7; y++) v.push_back(y*y);
    ll ans = INF;
    for (ll x = 0; x <= 1e+7; x++) {
        auto iter = lower_bound(v.begin(), v.end(), D-x*x);
        if (iter != v.end()) ans = min(ans, abs(x*x + *iter - D));
        if (iter != v.begin()) {
            iter--;
            ans = min(ans, abs(x*x + *iter - D));
        }
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
