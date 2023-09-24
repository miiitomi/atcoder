#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    int Q, K;
    cin >> Q >> K;

    vector<ll> dp(K+1, 0);
    dp[0] = 1;

    for (int q = 0; q < Q; q++) {
        char c;
        cin >> c;
        if (c == '+') {
            int x;
            cin >> x;
            for (int i = K; i >= 0; i--) {
                if (i - x < 0) break;;
                dp[i] = (dp[i] + dp[i-x]) % MOD;
            }
        } else {
            int x;
            cin >> x;
            for (int i = 0; i+x <= K; i++) {
                dp[i+x] = (dp[i+x] - dp[i] + MOD) % MOD;
            }
        }
        cout << dp[K] << endl;
    }
}
