// https://atcoder.jp/contests/abc211/tasks/abc211_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;
string chokudai = "chokudai";

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int M = chokudai.size();
    vector<vector<ll>> dp(M, vector<ll>(N+1, 0));
    for (int i = 0; i < M; i++) {
        char c = chokudai[i];
        if (i == 0) {
            for (int j = 0; j < N; j++) {
                dp[i][j+1] = dp[i][j];
                if (S[j] == c) dp[i][j+1]++;
            }
        } else {
            for (int j = 0; j < N; j++) {
                dp[i][j+1] = dp[i][j];
                if (S[j] == c) {
                    dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
                }
            }
        }
    }

    cout << dp[M-1][N] << endl;
}
