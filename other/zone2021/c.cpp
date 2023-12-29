#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(5, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < 5; j++) cin >> A[i][j];

    int left = 0, right = 1e+9 + 1;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(4, vector<bool>((1 << 5), false)));
        dp[0][0][0] = true;
        for (int i = 0; i < N; i++) {
            dp[i+1] = dp[i];
            for (int k = 0; k < 3; k++) {
                for (int s = 0; s < (1 << 5); s++) {
                    if (!dp[i][k][s]) continue;
                    int t = s;
                    for (int j = 0; j < 5; j++) if (A[i][j] >= mid) t = (t | (1 << j));
                    dp[i+1][k+1][t] = true;
                }
            }
        }

        if (dp[N][3][(1 << 5) - 1]) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
