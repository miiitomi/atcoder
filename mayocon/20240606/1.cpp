// https://atcoder.jp/contests/abc045/tasks/abc045_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, h;
    cin >> a >> b >> h;
    int ans = (a + b) * h / 2;
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
