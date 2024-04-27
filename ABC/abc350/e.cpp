#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, X, Y;
map<ll, double> dp;
double rec(ll n) {
    if (dp.count(n)) return dp[n];
    double a = X + rec(n / A);
    double b = 6 * Y;
    for (ll x = 2; x <= 6; x++) b += rec(n/x);
    b /= 5.0;
    return dp[n] = min(a, b);
}

void solve() {
    dp[0] = 0;
    ll N;
    cin >> N >> A >> X >> Y;
    double ans = rec(N);
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
