// https://atcoder.jp/contests/abc320/tasks/abc320_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmin(ll &l, ll r) {if (l > r) l = r;}

void solve() {
    ll N, H;
    cin >> N >> H;
    vector<ll> X(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> X[i];
    vector<ll> P(N+1, 0), F(N+1, 0);
    for (int i = 1; i <= N-1; i++) cin >> P[i] >> F[i];
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(H+1, vector<ll>(H+1, INF)));
    for (int k = 0; k <= H; k++) dp[0][H][k] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= H; j++) {
            for (int k = 0; k <= H; k++) {
                ll d = X[i] - X[i-1];
                if (d+j <= H && k >= d) chmin(dp[i][j][k], dp[i-1][j+d][k-d]);
                if (d+j <= H && min(k+F[i], H) >= d) chmin(dp[i][j][k], dp[i-1][j+d][min(k+F[i], H)-d] + P[i]);
                if (j >= F[i] && j-F[i]+d <= H && k >= d) chmin(dp[i][j][k], dp[i-1][j-F[i]+d][k-d] + P[i]);
                if (j == H && k >= d) for (int l = H; l >= d && l-d+F[i] >= H; l--) chmin(dp[i][j][k], dp[i-1][l][k-d] + P[i]);
            }
        }
    }
    ll ans = INF;
    for (int j = 0; j <= H; j++) ans = min(ans, dp[N][j][j]);
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
