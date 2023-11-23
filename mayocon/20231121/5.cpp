// https://atcoder.jp/contests/abc262/tasks/abc262_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;

    for (int K = 1; K <= N; K++) {
        vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(K, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < N; i++) {
            dp[i+1] = dp[i];
            ll y = A[i];
            for (int j = 0; j < K; j++) {
                for (int k = 0; k < K; k++) {
                    if (dp[i][j][k] > 0) {
                        int s = (k + y) % K;
                        dp[i+1][j+1][s] = (dp[i+1][j+1][s] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }
        ans = (ans + dp[N][K][0]) % MOD;
    }
    cout << ans << endl;
}
