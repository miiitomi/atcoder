// https://atcoder.jp/contests/abc083/tasks/abc083_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a+b > c+d) cout << "Left\n";
    else if (a+b == c+d) cout << "Balanced\n";
    else cout << "Right\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
