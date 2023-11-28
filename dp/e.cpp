#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, W, V=0;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        V += v[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(V+1, 2e+9));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j < V; j++) {
            if (j + v[i] <= V) {
                dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j] + w[i]);
            }
        }
    }

    ll ans = -1;
    for (ll x = 0; x <= V; x++) {
        if (dp[N][x] <= W) ans = max(ans, x);
    }

    cout << ans << endl;
}
