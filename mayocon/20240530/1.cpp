// https://atcoder.jp/contests/abc061/tasks/abc061_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= c && c <= b) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
