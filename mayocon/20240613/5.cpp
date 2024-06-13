// https://atcoder.jp/contests/abc232/tasks/abc232_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

void solve() {
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<mint>> dp(K+1, vector<mint>{0, 0, 0, 0});
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2) dp[0][3] = 1;
    else if (x1 == x2) dp[0][2] = 1;
    else if (y1 == y2) dp[0][1] = 1;
    else dp[0][0] = 1;

    for (int i = 0; i < K; i++) {
        dp[i+1][1] += dp[i][0];
        dp[i+1][2] += dp[i][0];
        dp[i+1][0] += (H + W - 2 - 2) * dp[i][0];

        dp[i+1][3] += dp[i][1];
        dp[i+1][1] += (H-1-1) * dp[i][1];
        dp[i+1][0] += (W-1) * dp[i][1];

        dp[i+1][3] += dp[i][2];
        dp[i+1][2] += (W-1-1) * dp[i][2];
        dp[i+1][0] += (H-1) * dp[i][2];

        dp[i+1][2] += (W-1) * dp[i][3];
        dp[i+1][1] += (H-1) * dp[i][3];
    }

    cout << dp[K][3].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
