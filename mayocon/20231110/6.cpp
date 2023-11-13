// https://atcoder.jp/contests/abc325/tasks/abc325_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    vector<ll> L(2), C(2), K(2);
    for (int i = 0; i < 2; i++) cin >> L[i] >> C[i] >> K[i];

    vector<vector<ll>> dp(N+1, vector<ll>(K[0] + 1, 1e+9));
    for (int j = 0; j <= K[0]; j++) dp[0][j] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K[0]; j++) {
            ll d = D[i];
            for (int w = 0; j + w <= K[0]; w++) {
                ll s = (d + L[1] - 1) / L[1];
                dp[i+1][j + w] = min(dp[i+1][j+w], s + dp[i][j]);
                d -= L[0];
                if (d < 0) d = 0;
            }
        }
    }

    ll ans = (ll)1e+18;

    for (int j = 0; j <= K[0]; j++) {
        if (dp[N][j] <= K[1]) {
            ll tmp = C[0] * j + C[1] * dp[N][j];
            ans = min(ans, tmp);
        }
    }

    if (ans == (ll)1e+18) cout << -1 << endl;
    else cout << ans << endl;
}
