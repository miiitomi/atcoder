// https://atcoder.jp/contests/abc253/tasks/abc253_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N, vector<ll>(M, 0));
    for (int j = 0; j < M; j++) dp[0][j] = 1;

    for (int i = 1; i < N; i++) {
        vector<ll> S(M+1, 0);
        for (int j = 0; j < M; j++) S[j+1] = (S[j] + dp[i-1][j]) % MOD;
        for (int j = 0; j < M; j++) {
            dp[i][j] = S[M];
            if (K > 0) {
                int l = max(0LL, j - K + 1), r = min(M-1, j + K - 1);
                dp[i][j] = (dp[i][j] - ((S[r+1] - S[l] + MOD) % MOD) + MOD) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < M; j++) ans = (ans + dp[N-1][j]) % MOD;
    cout << ans << endl;
}
