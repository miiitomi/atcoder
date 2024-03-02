// https://atcoder.jp/contests/abc099/tasks/abc099_c
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> dp(N+1, 1e+9);
    dp[0] = 0;
    for (int x = 0; x < N; x++) {
        dp[x+1] = min(dp[x+1], dp[x] + 1);
        for (int y = 6; x + y <= N; y *= 6) {
            dp[x+y] = min(dp[x+y], dp[x] + 1);
        }
        for (int y = 9; x + y <= N; y *= 9) {
            dp[x+y] = min(dp[x+y], dp[x] + 1);
        }
    }
    cout << dp.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
