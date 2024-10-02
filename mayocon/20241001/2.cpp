// https://atcoder.jp/contests/abc097/tasks/abc097_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll X;
    cin >> X;
    ll ans = 1;
    for (ll b = 2; b*b <= X; b++) {
        ll tmp = b*b;
        while (tmp <= X) {
            ans = max(ans, tmp);
            tmp *= b;
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
