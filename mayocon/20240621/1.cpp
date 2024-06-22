// https://atcoder.jp/contests/abc205/tasks/abc205_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    double a, b;
    cin >> a >> b;
    cout << (a/100.0)*b << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
