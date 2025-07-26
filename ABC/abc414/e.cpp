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
    mint n = (mint)N;
    mint ans = n * (n + 1) / 2;

    ll y = 1;
    while (y*y <= N) y++;
    y--;

    for (ll x = 1; x <= y; x++) {
        ans -= N/x;
        ll left = y, right = N+1;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            if (N/m < x) right = m;
            else left = m;
        }
        ans -= left - y;
    }
    cout << ans.val() << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
