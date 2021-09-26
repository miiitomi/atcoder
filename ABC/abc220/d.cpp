#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> dp(N, vector<int>(10, 0));
    dp[0][A[0]] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][(A[i] + j) % 10] += dp[i-1][j];
            dp[i][(A[i] + j) % 10] %= MOD;
            dp[i][(A[i] * j) % 10] += dp[i-1][j];
            dp[i][(A[i] * j) % 10] %= MOD;
        }
    }
    for (int j = 0; j < 10; j++) cout << dp[N-1][j] << endl;
}
