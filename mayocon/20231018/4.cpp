// https://atcoder.jp/contests/abc178/tasks/abc178_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll S;
    cin >> S;

    vector<vector<ll>> dp(S/3 + 1, vector<ll>(S+1, 0));

    for (int j = 3; j <= S; j++) dp[1][j] = 1;

    for (int i = 1; i < S/3; i++) {
        for (int j = 3; j <= S; j++) {
            if (j + 3 <= S) dp[i+1][j+3] = (dp[i+1][j+3] + dp[i][j]) % MOD;
            else break;
        }
        for (int j = 1; j <= S; j++) {
            dp[i+1][j] = (dp[i+1][j] + dp[i+1][j-1]) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= S/3; i++) ans = (ans + dp[i][S]) % MOD;

    cout << ans << endl;
}
