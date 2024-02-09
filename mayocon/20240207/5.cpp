// https://atcoder.jp/contests/abc201/tasks/abc201_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    vector<vector<int>> dp(H, vector<int>(W, 0)), is_takahashi(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        int c = i % 2;
        for (int j = 0; j < W; j++) {
            if (c == 0) is_takahashi[i][j] = 1;
            else is_takahashi[i][j] = 0;
            c = (c + 1) % 2;
        }
    }

    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (i == H-1 && j == W-1) continue;
            if (is_takahashi[i][j]) {
                int ans = 1e+9;
                if (i < H-1) {
                    if (A[i+1][j] == '+') ans = min(ans, dp[i+1][j] - 1);
                    else ans = min(ans, dp[i+1][j] + 1);
                }
                if (j < W-1) {
                    if (A[i][j+1] == '+') ans = min(ans, dp[i][j+1] - 1);
                    else ans = min(ans, dp[i][j+1] + 1);
                }
                dp[i][j] = ans;
            } else {
                int ans = -1e+9;
                if (i < H-1) {
                    if (A[i+1][j] == '+') ans = max(ans, dp[i+1][j] + 1);
                    else ans = max(ans, dp[i+1][j] - 1);
                }
                if (j < W-1) {
                    if (A[i][j+1] == '+') ans = max(ans, dp[i][j+1] + 1);
                    else ans = max(ans, dp[i][j+1] - 1);
                }
                dp[i][j] = ans;
            }
        }
    }

    if (dp[0][0] > 0) cout << "Aoki\n";
    if (dp[0][0] == 0) cout << "Draw\n";
    if (dp[0][0] < 0) cout << "Takahashi\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
