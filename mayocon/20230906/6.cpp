// https://atcoder.jp/contests/abc054/tasks/abc054_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(101, vector<ll>(101, 1e+9)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        ll x = a[i], y = b[i], z = c[i];
        for (int s = 0; s <= 100; s++) {
            if (s + x > 100) break;
            for (int t = 0; t <= 100; t++) {
                if (t + y > 100) break;
                dp[i+1][s+x][t+y] = min(dp[i+1][s+x][t+y], dp[i][s][t]+z);
            }
        }
    }

    ll ans = 1e+9;
    ll ma = Ma, mb = Mb;
    while (ma <= 100 && mb <= 100) {
        ans = min(ans, dp[N][ma][mb]);
        ma += Ma;
        mb += Mb;
    }

    if (ans == 1e+9) cout << -1 << endl;
    else cout << ans << endl;
}
