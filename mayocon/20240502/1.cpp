// https://atcoder.jp/contests/abc330/tasks/abc330_a
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, L;
    cin >> N >> L;
    int ans = 0;
    while (N--) {
        int a;
        cin >> a;
        ans += (a >= L);
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
