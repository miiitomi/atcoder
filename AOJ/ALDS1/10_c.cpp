#include <bits/stdc++.h>
using namespace std;

void solve() {
    string X, Y;
    cin >> X >> Y;
    int m = (int)X.size();
    int n = (int)Y.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            if (X[i] == Y[j]) dp[i+1][j+1] = max(dp[i+1][j+1], 1 + dp[i][j]);
        }
    }
    cout << dp[m][n] << endl;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) solve();
}
