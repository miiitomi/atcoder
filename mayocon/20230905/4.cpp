// https://atcoder.jp/contests/abc312/tasks/abc312_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c == '(' || c == '?') {
            for (int j = 0; j <= N-1; j++) {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            }
        }
        if (c == ')' || c == '?') {
            for (int j = 1; j <= N; j++) {
                dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[N][0] << endl;
}
