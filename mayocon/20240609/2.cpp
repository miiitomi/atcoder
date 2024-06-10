// https://atcoder.jp/contests/abc055/tasks/abc055_b
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)(1e+9) + 7;

void solve() {
    ll N;
    cin >> N;
    ll ans = 1;
    for (ll x = 1; x <= N; x++) {
        ans = (ans * x) % MOD;
    }
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
