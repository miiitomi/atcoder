#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e+9 + 7;

int main() {
    int K;
    cin >> K;

    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(1+K, 0);
    dp[0] = 1;
    for (int x = 1; x <= K; x++) {
        for (int y = 1; y <= min(9, x); y++) {
            dp[x] = (dp[x] + dp[x - y]) % MOD;
        }
    }
    cout << dp[K] << endl;
}
