#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N, vector<ll>(M, 0));
    for (int j = 0; j < M; j++) {
        dp[0][j] = 1;
    }

    vector<ll> S(M+1, 0);
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M+1; j++) {
            S[j] = (S[j-1] + dp[i-1][j-1]);
        }

        for (int j = 0; j < M; j++) {
            if (K == 0) {
                dp[i][j] = S[M] % MOD;
            } else {
                dp[i][j] = (S[M] - S[min(j + K , M)] + S[max(0LL, j-K+1)]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j < M; j++) {
        ans = (ans + dp[N-1][j]) % MOD;
    }
    cout << ans << endl;
}
