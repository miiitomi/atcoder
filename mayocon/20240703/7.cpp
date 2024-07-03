// https://atcoder.jp/contests/abc252/tasks/abc252_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> P(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> P[i];

    vector<vector<mint>> dp(N+1, vector<mint>(N+2, 0));
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 1;
        dp[i][i+1] = 1;
    }
    for (int k = 2; k <= N-1; k++) {
        for (int l = 2; l+k <= N+1; l++) {
            int r = l + k;
            dp[l][r] = dp[l+1][r];
            for (int m = l+1; m < r; m++) {
                if (P[l] < P[m]) {
                    dp[l][r] += dp[l+1][m]*dp[m][r];
                }
            }
        }
    }
    cout << dp[2][N+1].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
