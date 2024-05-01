// https://atcoder.jp/contests/abc178/tasks/abc178_c
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

void solve() {
    int N;
    cin >> N;
    vector<vector<mint>> dp(N, vector<mint>(4, 0));
    dp[0] = {8, 1, 1, 0};
    for (int k = 0; k < N-1; k++) {
        dp[k+1][0] = dp[k][0] * 8;
        dp[k+1][1] = dp[k][0] + dp[k][1] * 9;
        dp[k+1][2] = dp[k][0] + dp[k][2] * 9;
        dp[k+1][3] = dp[k][3]*10 + dp[k][1] + dp[k][2];
    }
    cout << dp.back().back().val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
