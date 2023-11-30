// https://atcoder.jp/contests/abc281/tasks/abc281_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K, D;
    cin >> N >> K >> D;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(K+1, vector<ll>(D, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        ll a = A[i];
        for (int k = 0; k < K; k++) {
            for (int d = 0; d < D; d++) {
                if (dp[i][k][d] < 0) continue;
                ll x = D*dp[i][k][d] + d + a;
                dp[i+1][k+1][x % D] = max(dp[i+1][k+1][x % D], x / D);
            }
        }
    }

    if (dp[N][K][0] < 0) cout << -1 << endl;
    else cout << D*dp[N][K][0] << endl;
}
