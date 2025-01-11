// https://atcoder.jp/contests/past19-open/tasks/past19_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll x, h, m, ans = 0;
    cin >> x >> h >> m;
    while (m != x) {
        m++;
        ans++;
        if (m == 60) {
            h++;
            m = 0;
        }
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
