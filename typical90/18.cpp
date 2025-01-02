// https://atcoder.jp/contests/typical90/tasks/typical90_r
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

double f(double d, double h) {
    double theta = atan2(h, d);
    return 180*theta/M_PI;
}

void solve() {
    ll T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    while (Q--) {
        ll E;
        cin >> E;
        double theta = -M_PI/2 + 2*M_PI*((E+0.0)/T);
        double x = 0, y = -(L/2.0)*cos(theta), z = (L/2.0)*(sin(theta)+1.0);
        double d = sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
        cout << f(d, z) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
