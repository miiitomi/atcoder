// https://atcoder.jp/contests/abc144/tasks/abc144_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    double a, b, x;
    cin >> a >> b >> x;
    double theta = 0;
    if (x <= (a*a*b/2)) {
        theta = atan((2.0*x)/(a*b*b));
    } else {
        theta = atan((a*a*a)/(2.0*(a*a*b - x)));
    }
    double ans = 90.0 - theta * (180.0/M_PI);
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
