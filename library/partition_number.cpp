// partition number (bunkatsu-su)
// https://manabitimes.jp/math/888
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
    for (int i = 1; i <= M; i++) {
        dp[i][i] = 1;
        for (int j = i+1; j <= N; j++) {
            dp[i][j] = dp[i][j-i] + dp[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) ans += dp[i][N];
    cout << ans << endl;
}
