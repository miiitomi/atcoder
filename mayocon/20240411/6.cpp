// https://atcoder.jp/contests/abc248/tasks/abc248_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint;

void solve() {
    int N, P;
    cin >> N >> P;
    mint::set_mod(P);

    vector<vector<vector<mint>>> dp(N+100, vector<vector<mint>>(N+100, vector<mint>(2, 0)));
    dp[2][0] = {1, 0};
    dp[2][1] = {4, 0};
    dp[2][2] = {0, 3};
    for (int i = 2; i <= N-1; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j+1][0] += 3*dp[i][j][0];
            dp[i+1][j+2][1] += 2*dp[i][j][0];
            dp[i+1][j][0] += dp[i][j][1];
            dp[i+1][j+1][1] += dp[i][j][1];
        }
    }
    for (int j = 1; j <= N-1; j++) {
        cout << dp[N][j][0].val() << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
