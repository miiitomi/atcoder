// https://atcoder.jp/contests/abc350/tasks/abc350_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll A, X, Y;

map<ll, double> dp;
double rec(ll N) {
    if (N == 0) return 0.0;
    if (dp.contains(N)) return dp[N];
    double a = X + rec(N/A);
    double b = 6 * Y;
    for (ll k = 2; k <= 6; k++) b += rec(N/k);
    b /= 5.0;
    dp[N] = min(a, b);
    return dp[N];
}

void solve() {
    ll N;
    cin >> N >> A >> X >> Y;
    cout << rec(N) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
