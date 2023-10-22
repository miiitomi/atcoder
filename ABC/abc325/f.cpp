#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    ll L1, C1, K1, L2, C2, K2;
    cin >> L1 >> C1 >> K1 >> L2 >> C2 >> K2;

    vector<vector<ll>> dp(N+1, vector<ll>(K1+1, -1));
    dp[0][K1] = K2;

    for (int i = 0; i < N; i++) {
        for (int k1 = K1; k1 >= 0; k1--) {
            if (dp[i][k1] < 0) continue;
            for (int a = 0; a <= k1; a++) {
                ll x = D[i] - a * L1;
                if (x <= 0) dp[i+1][k1-a] = max(dp[i+1][k1-a], dp[i][k1]);
                else {
                    ll b = x / L2;
                    if (x % L2 != 0) b++;
                    if (b <= dp[i][k1]) dp[i+1][k1-a] = max(dp[i+1][k1-a], dp[i][k1]-b);
                }
            }
        }
    }

    ll ans = 1e+18;
    for (int k1 = 0; k1 <= K1; k1++) {
        if (dp[N][k1] >= 0) ans = min(ans, C1*(K1 - k1) + C2*(K2 - dp[N][k1]));
    }
    if (ans == 1e+18) cout << -1 << endl;
    else cout << ans << endl;
}
