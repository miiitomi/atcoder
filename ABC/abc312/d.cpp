#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<vector<ll>> dp(N, vector<ll>((N/2)+1, 0));

    if (S[0] == ')') {
        cout << 0 << endl;
        return 0;
    } else dp[0][1] = 1;

    for (int i = 1; i < N; i++) {
        if (S[i] == '(') {
            for (int j = 0; j < N/2; j++) {
                dp[i][j+1] = dp[i-1][j];
            }
        } else if (S[i] == ')') {
            for (int j = 1; j <= N/2; j++) {
                dp[i][j-1] = dp[i-1][j];
            }
        } else {
            for (int j = 0; j < N/2; j++) {
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
            }
            for (int j = 1; j <= N/2; j++) {
                dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            }  
        }
    }

    cout << dp[N-1][0] << endl;
}
