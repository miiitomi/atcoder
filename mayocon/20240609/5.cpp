// https://atcoder.jp/contests/abc129/tasks/abc129_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e+9 + 7;

void solve() {
    string L;
    cin >> L;
    ll N = L.size();
    vector<vector<ll>> dp(N, {0, 0});
    dp[0] = {1, 2};
    for (int i = 0; i < N-1; i++) {
        dp[i+1][0] = dp[i][0] * 3 % MOD;
        if (L[i+1] == '0') {
            dp[i+1][1] = dp[i][1];
        } else {
            dp[i+1][1] = dp[i][1] * 2 % MOD;
            dp[i+1][0] = (dp[i+1][0] + dp[i][1]) % MOD;
        }
    }

    cout << (dp.back()[0] + dp.back()[1]) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
