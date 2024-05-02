// https://atcoder.jp/contests/abc087/tasks/abc087_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, X, ans=0;
    cin >> a >> b >> c >> X;

    for (int x = 0; x <= a; x++) {
        for (int y = 0; y <= b; y++) {
            for (int z = 0; z <= c; z++) {
                int s = x*500 + y*100 + z * 50;
                if (s == X) ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
