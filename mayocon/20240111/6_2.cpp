// https://atcoder.jp/contests/abc147/tasks/abc147_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0)), B(H, vector<int>(W, 0)), X(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        cin >> B[i][j];
        X[i][j] = abs(A[i][j] - B[i][j]);
    }

    int m = 80 * (H+W);
    vector<vector<vector<bool>>> dp1(H, vector<vector<bool>>(W, vector<bool>(2*m + 1, false)));
    dp1[0][0][m + X[0][0]] = true;
    dp1[0][0][m - X[0][0]] = true;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int x = 0; x <= 2*m; x++) {
                if (dp1[i][j][x]) {
                    if (i+1 < H) {
                        dp1[i+1][j][x+X[i+1][j]] = true;
                        dp1[i+1][j][x-X[i+1][j]] = true;
                    }
                    if (j+1 < W) {
                        dp1[i][j+1][x+X[i][j+1]] = true;
                        dp1[i][j+1][x-X[i][j+1]] = true;
                    }
                }
            }
        }
    }

    int ans = 1e+9;
    for (int x = 0; x <= 2*m; x++) {
        if (dp1[H-1][W-1][x]) {
            ans = min(ans, abs(x - m));
        }
    }

    cout << ans << endl;
}
