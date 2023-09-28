// https://atcoder.jp/contests/abc310/tasks/abc310_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
string S;

int main() {
    cin >> N >> S;
    vector<vector<ll>> dp(N, vector<ll>(2, 0));

    if (S[0] == '0') dp[0][0] = 1;
    else dp[0][1] = 1;

    for (ll i = 1; i < N; i++) {
        if (S[i] == '0') {
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][0] = 1;
        } else {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) ans += dp[i][1];
    cout << ans << endl;
}
