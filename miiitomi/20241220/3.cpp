// https://atcoder.jp/contests/abc254/tasks/abc254_d
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
    ll ans = 0;
    for (ll a = 1; a <= N; a++) {
        ll x = a;
        for (ll y = 2; y*y <= x; y++) {
            while (x % (y*y) == 0) x /= y*y;
        }
        ll left = 1, right = N+1;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            if (x*m*m > N) right = m;
            else left = m;
        }
        ans += left;
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
