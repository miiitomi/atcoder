// https://atcoder.jp/contests/abc144/tasks/abc144_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    if (2*x <= a*a*b) {
        double theta = M_PI/2.0 - atan((2.0*x)/(double(a*b*b)));
        theta *= (180 / M_PI);
        cout << theta << endl;
    } else {
        double left = 0, right = M_PI/2.0 - atan((double)a/(double)b);
        for (int k = 0; k < 100; k++) {
            double t = (right + left) / 2.0;
            double y = ((a / cos(t)) * b * sin(M_PI/2.0 - t) - a*a*tan(t)/2.0) * a;
            if (y > x) left = t;
            else right = t;
        }
        double theta = (left + right) / 2.0;
        theta *= (180 / M_PI);
        cout << theta << endl;
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
