#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    int N;
    string S;
    cin >> N >> S;

    string atcoder = "atcoder";
    vector<vector<ll>> dp(8, vector<ll>(N+1, 0));
    dp[7].assign(N+1, 1);

    for (int i = 6; i >= 0; i--) {
        char c = atcoder[i];
        for (int j = N-1; j >= 0; j--) {
            dp[i][j] = dp[i][j+1];
            if (S[j] == c) dp[i][j] = (dp[i][j] + dp[i+1][j+1]) % MOD;
        }
    }

    cout << dp[0][0] << endl;
}
