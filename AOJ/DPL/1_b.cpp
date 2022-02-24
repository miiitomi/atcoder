#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i+1][j] = dp[i][j];
            if (j >= w[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
        }
    }
    cout << dp[N][W] << endl;
}
