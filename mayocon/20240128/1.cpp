// https://atcoder.jp/contests/abc202/tasks/abc202_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    a = 7 - a;
    b = 7 - b;
    c = 7 - c;
    cout << a + b + c << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
