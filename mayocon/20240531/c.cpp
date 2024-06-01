// https://atcoder.jp/contests/abc027/tasks/abc027_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) cout << c << "\n";
    else if (b == c) cout << a << "\n";
    else cout << b << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
