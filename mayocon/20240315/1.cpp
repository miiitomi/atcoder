// https://atcoder.jp/contests/abc112/tasks/abc112_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, T;
    cin >> N >> T;
    int ans = 1e+9;
    for (int i = 0; i < N; i++) {
        int c, t;
        cin >> c >> t;
        if (t <= T) {
            ans = min(ans, c);
        }
    }

    if (ans < (int)1e+9) cout << ans << endl;
    else cout << "TLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
