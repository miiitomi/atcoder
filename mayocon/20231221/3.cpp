// https://atcoder.jp/contests/abc286/tasks/abc286_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<vector<int>> dp(N+1, vector<int>(X+1, 1e+9));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= X; j++) if (dp[i][j] < 1e+9) dp[i+1][j] = 0;
        for (int j = 0; j <= X; j++) {
            if (dp[i+1][j] < 1e+9 && j + a <= X && dp[i+1][j] < b) {
                dp[i+1][j+a] = min(dp[i+1][j+a], dp[i+1][j] + 1);
            }
        }
    }

    if (dp[N][X] < 1e+9) cout << "Yes" << endl;
    else cout << "No" << endl;
}
