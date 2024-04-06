#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, C;
    cin >> a >> b >> C;
    vector<vector<vector<pair<ll,ll>>>> dp(61, vector<vector<pair<ll,ll>>>(a+1, vector<pair<ll,ll>>(b+1, {-1,-1})));
    dp[0][0][0] = {0, 0};
    for (ll i = 0; i < 60; i++) {
        for (ll s = 0; s <= a; s++) {
            for (ll t = 0; t <= b; t++) {
                if (dp[i][s][t].first < 0) continue;
                if ((C & (1LL << i)) == 0LL) {
                    dp[i+1][s][t] = dp[i][s][t];
                    if (s+1 <= a && t+1 <= b) dp[i+1][s+1][t+1] = {dp[i][s][t].first + (1LL << i), dp[i][s][t].second + (1LL << i)};
                } else {
                    if (s+1 <= a) dp[i+1][s+1][t] = {dp[i][s][t].first + (1LL << i), dp[i][s][t].second};
                    if (t+1 <= b) dp[i+1][s][t+1] = {dp[i][s][t].first, dp[i][s][t].second + (1LL << i)};
                }
            }
        }
    }

    if (dp.back()[a][b].first < 0) cout << "-1\n";
    else cout << dp.back()[a][b].first << " " << dp.back()[a][b].second << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
