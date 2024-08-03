// https://atcoder.jp/contests/abc279/tasks/abc279_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double f(double A, double B, double g) {
    if (g <= 1.0) return A;
    return (g-1)*B + A/sqrt(g);
}

void solve() {
    double A, B;
    cin >> A >> B;
    double left = 0.0, right = 1e+9;
    for (int k = 0; k < 100; k++) {
        double m = (right + left)/2;
        if (m*m*m > A/(2.0*B)) right = m;
        else left = m;
    }
    double g = left * left;
    double ans = 9e+18;
    for (ll x = max(1.0, g-5); x <= g+5; x++) {
        ans = min(ans, f(A, B, x));
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
