#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<vector<bool>> dp(N+1, vector<bool>(X+1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= X; j++) {
            if (!dp[i][j]) continue;
            if (j + a <= X) dp[i+1][j+a] = true;
            if (j + b <= X) dp[i+1][j+b] = true;
        }
    }
    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
