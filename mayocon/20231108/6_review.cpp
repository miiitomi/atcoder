// https://atcoder.jp/contests/abc249/tasks/abc249_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, P;
    cin >> N >> P;
    vector<vector<ll>> dp(N+2, vector<ll>(N+2, 0));
    for (ll t = 0; t < N; t++) {
        for (ll s = 0; s <= N; s++) dp[s+1][t] = (dp[s+1][t] + dp[s][t]) % P;
        for (ll s = 0; s < N; s++) {
            ll x = 25*dp[s][t]%P;
            if (s == 0 && t == 0) x = 26;
            dp[min(s+1, N+1)][min(t+2, N+1)] = (dp[min(s+1, N+1)][min(t+2, N+1)] + x) % P;
            dp[min(s+10, N+1)][min(t+2, N+1)] = (dp[min(s+10, N+1)][min(t+2, N+1)] - x + P) % P;
            dp[min(s+10, N+1)][min(t+3, N+1)] = (dp[min(s+10, N+1)][min(t+3, N+1)] + x) % P;
            dp[min(s+100, N+1)][min(t+3, N+1)] = (dp[min(s+100, N+1)][min(t+3, N+1)] - x + P) % P;
            dp[min(s+100, N+1)][min(t+4, N+1)] = (dp[min(s+100, N+1)][min(t+4, N+1)] + x) % P;
            dp[min(s+1000, N+1)][min(t+4, N+1)] = (dp[min(s+1000, N+1)][min(t+4, N+1)] - x + P) % P;
            dp[min(s+1000, N+1)][min(t+5, N+1)] = (dp[min(s+1000, N+1)][min(t+5, N+1)] + x) % P;
        }
    }

    ll ans = 0;
    for (ll t = 2; t < N; t++) ans = (ans + dp[N][t]) % P;
    cout << ans << endl;
}
