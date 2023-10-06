// https://atcoder.jp/contests/abc291/tasks/abc291_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for (int i = 1; i < N; i++) {
        if (A[i-1] != A[i]) dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
        if (B[i-1] != A[i]) dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        if (A[i-1] != B[i]) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        if (B[i-1] != B[i]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
    }

    cout << (dp[N-1][0] + dp[N-1][1]) % MOD << endl;
}
