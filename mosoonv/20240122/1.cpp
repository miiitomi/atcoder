// https://atcoder.jp/contests/abc193/tasks/abc193_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    const int INF = 2e+9;
    int ans = INF;
    for (int i = 0; i < N; i++) {
        int a, p, x;
        cin >> a >> p >> x;
        x -= a;
        if (x > 0) ans = min(ans, p);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
