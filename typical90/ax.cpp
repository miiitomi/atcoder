#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> dp(N+1, -1);
    dp[N] = 1;
    for (int i = N-1; i >= 0; i--) {
        if (i + L <= N) dp[i] = dp[i+1] + dp[i+L];
        else dp[i] = dp[i+1];
        dp[i] %= MOD;
    }
    cout << dp[0] << endl;
}
