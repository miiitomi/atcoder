// https://atcoder.jp/contests/abc230/tasks/abc230_e
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
    ll x = 1;
    ll ans = 0;
    while (x <= N) {
        ll left = x, right = N+1;
        while (right - left > 1) {
            ll m = (left + right)/2;
            if (N/m == N/x) left = m;
            else right = m;
        }
        ans += (left - x + 1) * (N/x);
        x = right;
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
