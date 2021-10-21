#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    int K;
    cin >> K;

    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(K+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[K] << endl;
}
