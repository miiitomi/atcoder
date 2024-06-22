// https://atcoder.jp/contests/abc057/tasks/abc057_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll g(ll x) {
    ll ans = 1, y = 9;
    while (x > y) {
        ans++;
        y = 10*y + 9;
    }
    return ans;
}

void solve() {
    ll N;
    cin >> N;
    ll ans = 1e+9;
    for (ll x = 1; x*x <= N; x++) {
        if (N%x != 0) continue;
        ll y = N/x;
        ans = min(ans, g(y));
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
