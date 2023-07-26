#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '#') {
                if (i < N-1) {
                    S[i+1][j] = '#';
                    if (j < M-1) S[i+1][j+1] = '#';
                }
            }
        }
    }

    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    dp[0][M] = 1;
    ll cum_sum;
    ll new_sum = 1;

    for (int c = 1-M; c <= N-1; c++) {
        cum_sum = new_sum;
        new_sum = 0;
        for (int i = 0; i <= N; i++) {
            int j = i - c;

            if (j < 0 || j > M) continue;

            if (i == 0) {
                dp[i][j] = cum_sum;
                new_sum = (new_sum + dp[i][j]) % MOD;
                continue;
            }

            dp[i][j] = cum_sum;
            cum_sum = (cum_sum - dp[i-1][j] + MOD) % MOD;
            if (S[i-1][j-1] == '#') dp[i][j] = 0;
            new_sum = (new_sum + dp[i][j]) % MOD;
        }
    }

    cout << (dp[N-1][0] + dp[N][1]) % MOD << endl;
}
