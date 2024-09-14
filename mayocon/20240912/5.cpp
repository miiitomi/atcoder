// https://atcoder.jp/contests/abc262/tasks/abc262_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    mint ans = N;
    for (ll K = 2; K <= N; K++) {
        vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(K+1, vector<mint>(K, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < N; i++) {
            dp[i+1] = dp[i];
            for (int k = 0; k < K; k++) {
                for (int l = 0; l < K; l++) {
                    dp[i+1][k+1][(l+a[i])%K] += dp[i][k][l];
                }
            }
        }
        ans += dp[N][K][0];
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
