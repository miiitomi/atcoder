#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<ll>> dp(N+1, vector<ll>(min(N, M+1)+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= min(N, M+1); k++) {
            if (S[i]) {
                if (k == M+1) continue;
                dp[i+1][k+1] = (dp[i+1][k+1] + dp[i][k]) % MOD;
            } else {
                dp[i+1][k] = (dp[i+1][k] + dp[i][k]*k) % MOD;
                if (M - k > 0) dp[i+1][k+1] = (dp[i+1][k+1] + dp[i][k] * (M-k)) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int k = 0; k < (int)dp[0].size(); k++) ans = (ans + dp[N][k]) % MOD;
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
