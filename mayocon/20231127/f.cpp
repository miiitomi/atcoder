// https://atcoder.jp/contests/abc054/tasks/abc054_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, ma, mb;
    cin >> N >> ma >> mb;
    vector<ll> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<ll>> dp(200, vector<ll>(200, (ll)1e+18));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int s = a[i], t = b[i];
        for (int x = 199; x >= 0; x--) {
            for (int y = 199; y >= 0; y--) {
                if (x+s < 200 && y+t < 200) dp[x+s][y+t] = min(dp[x+s][y+t], dp[x][y] + c[i]);
            }
        }
    }

    ll ans = 1e+18;
    for (int k = 1; max(k*ma, k*mb) < 200; k++) {
        ans = min(ans, dp[k*ma][k*mb]);
    }
    if (ans == (ll)1e+18) cout << -1 << endl;
    else cout << ans << endl;
}
