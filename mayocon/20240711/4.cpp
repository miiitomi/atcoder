// https://atcoder.jp/contests/abc148/tasks/abc148_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << endl;
        return;
    }
    ll ans = N/2;
    ll tmp = 0;
    for (ll k = 1; k <= 100; k++) {
        ll x = 1;
        for (ll i = 0; i < k; i++) x *= 5;
        if (x > (ll)1e+18) break;
        tmp += ((N/x)/2);
    }
    ans = min(ans, tmp);
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
