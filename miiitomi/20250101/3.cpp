// https://atcoder.jp/contests/abc280/tasks/abc280_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll f(ll x, ll cnt) {
    ll left = 1, right = (ll)1e+12;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        ll y = 1, tmp = 0;
        for (ll k = 1; k <= 100; k++) {
            y *= x;
            if (y > m) break;
            tmp += m/y;
            if (tmp >= cnt) break;
        }
        if (tmp >= cnt) right = m;
        else left = m;
    }
    return right;
}

void solve() {
    ll K, ans = 1;
    cin >> K;
    for (ll x = 2; x*x <= K; x++) {
        if (K % x) continue;
        ll cnt = 0;
        while (K % x == 0) {
            cnt++;
            K /= x;
        }
        ans = max(ans, f(x, cnt));
    }
    ans = max(ans, K);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
