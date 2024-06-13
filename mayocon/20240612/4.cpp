// https://atcoder.jp/contests/abc219/tasks/abc219_d
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(X+1, vector<int>(Y+1, 1e+9)));
    dp[0][0][0] = 0;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    for (int i = 0; i < N; i++) {
        int a = A[i], b = B[i];
        dp[i+1] = dp[i];
        for (int x = 0; x <= X; x++) {
            for (int y = 0; y <= Y; y++) {
                dp[i+1][min(x+a, X)][min(y+b, Y)] = min(dp[i+1][min(x+a, X)][min(y+b, Y)], dp[i][x][y] + 1);
            }
        }
    }

    if (dp[N][X][Y] == (int)1e+9) cout << -1 << endl;
    else cout << dp[N][X][Y] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
