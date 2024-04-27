// https://atcoder.jp/contests/abc144/tasks/abc144_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a <= 9 && b <= 9) cout << a*b << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
