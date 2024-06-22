// https://atcoder.jp/contests/abc127/tasks/abc127_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a >= 13) cout << b << endl;
    else if (a >= 6) cout << b/2 << endl;
    else cout << 0 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
