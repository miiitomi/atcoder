// https://atcoder.jp/contests/abc303/tasks/abc303_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;
    ll N = S.size();
    vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'a') {
            dp[i+1][0] = min(dp[i][0]+X, dp[i][1]+Z+X);
            dp[i+1][1] = min(dp[i][0]+Z+Y, dp[i][1]+Y);
        } else {
            dp[i+1][0] = min(dp[i][0]+Y, dp[i][1]+Z+Y);
            dp[i+1][1] = min(dp[i][0]+Z+X, dp[i][1]+X);
        }
    }

    cout << min(dp.back()[0], dp.back()[1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
