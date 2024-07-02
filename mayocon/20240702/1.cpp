// https://atcoder.jp/contests/abc114/tasks/abc114_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    if (x == 3 || x == 5 || x == 7) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
