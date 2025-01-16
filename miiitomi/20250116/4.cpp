// https://atcoder.jp/contests/abc192/tasks/abc192_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = INF;
    for (ll K = 1; K <= N; K++) {
        vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(K, -1)));
        dp[0][0][0] = 0;
        for (int i = 0; i < N; i++) {
            dp[i+1] = dp[i];
            for (int k = 0; k < K; k++) {
                for (int m = 0; m < K; m++) {
                    if (dp[i][k][m] < 0) continue;
                    ll s = dp[i][k][m] + A[i];
                    ll n = s % K;
                    dp[i+1][k+1][n] = max(dp[i+1][k+1][n], s);
                }
            }
        }
        for (ll m = 0; m < K; m++) {
            if (dp[N][K][m] < 0 || (X-m)%K) continue;
            ans = min(ans, (X-dp[N][K][m])/K);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
