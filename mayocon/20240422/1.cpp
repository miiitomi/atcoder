// https://atcoder.jp/contests/abc305/tasks/abc305_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int ans = 1e+9, v = 1e+9;
    for (int x = 0; x <= 100; x += 5) {
        if (v > abs(N-x)) {
            v = abs(N-x);
            ans = x;
        }
    }
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
