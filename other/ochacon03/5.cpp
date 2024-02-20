#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll X = 62;

void solve() {
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<ll>>> dp(X+1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[X][0][0] = 1;
    for (ll i = X-1; i >= 0; i--) {
        bool a = (A & (1LL << i));
        bool b = (B & (1LL << i));
        bool c = (C & (1LL << i));
        dp[i][1][1] += 2 * dp[i+1][1][1];
        dp[i][1][0] += dp[i+1][1][0];
        if (b) dp[i][1][1] += dp[i+1][1][0];
        dp[i][0][1] += dp[i+1][0][1];
        if (a) dp[i][1][1] += dp[i+1][0][1];
        if (c) {
            if (a && b) {
                dp[i][0][1] += dp[i+1][0][0];
                dp[i][1][0] += dp[i+1][0][0];
            } else if ((a && !b) || (!a && b)) {
                dp[i][0][0] += dp[i+1][0][0];
            }
        } else {
            if (a && b) {
                dp[i][0][0] += dp[i+1][0][0];
                dp[i][1][1] += dp[i+1][0][0];
            } else if (a && !b) {
                dp[i][1][0] += dp[i+1][0][0];
            } else if (!a && b) {
                dp[i][0][1] += dp[i+1][0][0];
            } else {
                dp[i][0][0] += dp[i+1][0][0];
            }
        }
    }

    cout << dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
