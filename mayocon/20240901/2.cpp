// https://atcoder.jp/contests/abc196/tasks/abc196_c
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
    for (ll x = 1; x <= (ll)1e+6; x++) {
        string y = to_string(x);
        y = y + y;
        ll X = stoll(y);
        if (X <= N) ans++;
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
