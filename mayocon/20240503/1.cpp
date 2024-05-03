// https://atcoder.jp/contests/abc078/tasks/abc078_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int i = Z, cnt = 0;
    while (i + Y + Z <= X) {
        cnt++;
        i += Y+Z;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
