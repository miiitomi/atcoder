// https://atcoder.jp/contests/abc347/tasks/abc347_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll a, b, C;
    cin >> a >> b >> C;
    vector<vector<vector<pair<ll,ll>>>> dp(61, vector<vector<pair<ll,ll>>>(a+1, vector<pair<ll,ll>>(b+1, {-1, -1})));
    dp[0][0][0] = {0, 0};
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k <= b; k++) {
                if (dp[i][j][k].first == -1) continue;
                if (C & (1LL << i)) {
                    if (j < a) dp[i+1][j+1][k] = {dp[i][j][k].first + (1LL << i), dp[i][j][k].second};
                    if (k < b) dp[i+1][j][k+1] = {dp[i][j][k].first, dp[i][j][k].second + (1LL << i)};
                } else {
                    dp[i+1][j][k] = dp[i][j][k];
                    if (j < a && k < b) dp[i+1][j+1][k+1] = {dp[i][j][k].first + (1LL << i), dp[i][j][k].second + (1LL << i)};
                }
            }
        }
    }
    if (dp.back()[a][b].first == -1) cout << -1 << endl;
    else cout << dp.back()[a][b].first << " " << dp.back()[a][b].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
