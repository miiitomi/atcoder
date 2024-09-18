// https://atcoder.jp/contests/abc292/tasks/abc292_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, B;
    cin >> A >> B;
    if (B < A) swap(A, B);
    double left = 0, right = M_PI * (30.0/180);
    for (int k = 0; k < 100; k++) {
        double theta = (left + right) / 2.0;
        double x = A * tan(theta);
        double y = cos(theta + M_PI * (30.0/180)) * A / cos(theta);
        if (x+y <= B) left = theta;
        else right = theta;
    }
    double ans = A/cos(left);
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
