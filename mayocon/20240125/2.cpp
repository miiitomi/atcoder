// https://atcoder.jp/contests/abc168/tasks/abc168_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;

    double x1 = a * cos((h + m/60.0)/12.0 * 2 * M_PI);
    double y1 = a * sin((h + m/60.0)/12.0 * 2 * M_PI);
    double x2 = b * cos(m/60.0 * 2 * M_PI);
    double y2 = b * sin(m/60.0 * 2 * M_PI);

    cout << sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
