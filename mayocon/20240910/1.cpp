// https://atcoder.jp/contests/abc135/tasks/abc135_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll m = (a + b) / 2LL;
    for (ll x = m-1; x <= m+1; x++) {
        if (abs(a-x) == abs(b-x)) {
            cout << x << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
