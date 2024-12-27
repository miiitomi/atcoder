// https://atcoder.jp/contests/abc060/tasks/arc073_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
    ll w0 = w[0];
    for (int i = 0; i < N; i++) w[i] -= w0;
    vector<vector<ll>> dp(N+1, vector<ll>(3*N + 1, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<vector<ll>> ndp = dp;
        for (int k = 0; k < N; k++) {
            for (int x = 0; x+w[i] <= 3*N; x++) {
                if (dp[k][x] < 0) continue;
                ndp[k+1][x+w[i]] = max(ndp[k+1][x+w[i]], dp[k][x] + v[i]);
            }
        }
        swap(dp, ndp);
    }
    ll ans = 0;
    for (int k = 1; k <= N; k++) {
        for (int x = 0; x <= 3*N; x++) {
            if (k*w0 + x <= W) {
                ans = max(ans, dp[k][x]);
            }
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
