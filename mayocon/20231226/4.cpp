// https://atcoder.jp/contests/abc208/tasks/abc208_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N, vector<ll>(N, 1e+18)));
    for (int j = 0; j < N; j++) dp[0][j][j] = 0;

    while (M--) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dp[0][a][b] = c;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                dp[i+1][a][b] = min(dp[i][a][b], dp[i][a][i] + dp[i][i][b]);
                if (dp[i+1][a][b] < (ll)1e+18) ans += dp[i+1][a][b];
            }
        }
    }
    cout << ans << endl;
}
