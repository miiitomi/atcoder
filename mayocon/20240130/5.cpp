// https://atcoder.jp/contests/abc232/tasks/abc232_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll H, W, K;
    cin >> H >> W >> K;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<vector<vector<ll>>> dp(K+1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[0][x1 == x2][y1 == y2] = 1;

    for (int k = 1; k <= K; k++) {
        dp[k][0][0] = (dp[k][0][0] + (H+W-4) * dp[k-1][0][0]) % MOD;
        dp[k][0][1] = (dp[k][0][1] + 1 * dp[k-1][0][0]) % MOD;
        dp[k][1][0] = (dp[k][1][0] + 1 * dp[k-1][0][0]) % MOD;
        dp[k][1][1] = (dp[k][1][1] + 0 * dp[k-1][0][0]) % MOD;

        dp[k][0][0] = (dp[k][0][0] + (W-1) * dp[k-1][0][1]) % MOD;
        dp[k][0][1] = (dp[k][0][1] + (H-2) * dp[k-1][0][1]) % MOD;
        dp[k][1][0] = (dp[k][1][0] + 0 * dp[k-1][0][1]) % MOD;
        dp[k][1][1] = (dp[k][1][1] + 1 * dp[k-1][0][1]) % MOD;

        dp[k][0][0] = (dp[k][0][0] + (H-1) * dp[k-1][1][0]) % MOD;
        dp[k][0][1] = (dp[k][0][1] + 0 * dp[k-1][1][0]) % MOD;
        dp[k][1][0] = (dp[k][1][0] + (W-2) * dp[k-1][1][0]) % MOD;
        dp[k][1][1] = (dp[k][1][1] + 1 * dp[k-1][1][0]) % MOD;

        dp[k][0][0] = (dp[k][0][0] + 0 * dp[k-1][1][1]) % MOD;
        dp[k][0][1] = (dp[k][0][1] + (H-1) * dp[k-1][1][1]) % MOD;
        dp[k][1][0] = (dp[k][1][0] + (W-1) * dp[k-1][1][1]) % MOD;
        dp[k][1][1] = (dp[k][1][1] + 0 * dp[k-1][1][1]) % MOD;
    }

    cout << dp[K][1][1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
