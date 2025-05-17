#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;

    ll M = 1;
    while ((1LL << M) <= N) M++;

    vector<vector<vector<pair<ll,ll>>>> dp(M, vector<vector<pair<ll,ll>>>(K+1, vector<pair<ll,ll>>(2, {0, 0})));
    dp[M-1][0][0] = {1, 0};
    dp[M-1][1][1] = {1, (1LL << (M-1))%MOD};

    for (ll m = M-1; m >= 1; m--) {
        for (ll k = 0; k <= K; k++) {
            dp[m-1][k][0].first += dp[m][k][0].first;
            dp[m-1][k][0].second += dp[m][k][0].second;
            dp[m-1][k][0].second %= MOD;

            if (k < K) {
                dp[m-1][k+1][0].first += dp[m][k][0].first;
                dp[m-1][k+1][0].second += dp[m][k][0].second + (1LL << (m-1)) % MOD * dp[m][k][0].first % MOD;
                dp[m-1][k+1][0].second %= MOD;
            }

            if (N & (1LL << (m-1))) {
                dp[m-1][k][0].first += dp[m][k][1].first;
                dp[m-1][k][0].second += dp[m][k][1].second;
                dp[m-1][k][0].second %= MOD;
                if (k < K) {
                    dp[m-1][k+1][1].first += dp[m][k][1].first;
                    dp[m-1][k+1][1].second += dp[m][k][1].second + (1LL << (m-1)) % MOD * dp[m][k][1].first % MOD;
                    dp[m-1][k+1][1].second %= MOD;
                }
            } else {
                dp[m-1][k][1].first += dp[m][k][1].first;
                dp[m-1][k][1].second += dp[m][k][1].second;
                dp[m-1][k][1].second %= MOD;
            }
        }
    }

    cout << (dp[0][K][0].second + dp[0][K][1].second)%MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
