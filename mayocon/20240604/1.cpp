// https://atcoder.jp/contests/abc100/tasks/abc100_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a <= 8 && b <= 8) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
