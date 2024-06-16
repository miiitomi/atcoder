// https://atcoder.jp/contests/abc185/tasks/abc185_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L;
    cin >> L;
    vector<vector<ll>> dp(L, vector<ll>(12, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= L-2; i++) {
        dp[i+1] = dp[i];
        for (int x = 0; x <= 10; x++) {
            dp[i+1][x+1] += dp[i][x];
        }
    }
    cout << dp[L-1][11] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
