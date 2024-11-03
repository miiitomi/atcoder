// https://atcoder.jp/contests/abc147/tasks/abc147_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, m = 0;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W)), B(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            m = max(m, A[i][j]);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
            m = max(m, B[i][j]);
        }
    }
    ll M = (H+W-1)*m;
    vector<vector<vector<bool>>> dp(H, vector<vector<bool>>(W, vector<bool>(2*M+1, false)));
    dp[0][0][M+A[0][0]-B[0][0]] = true;
    dp[0][0][M-A[0][0]+B[0][0]] = true;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k <= 2*M; k++) {
                if (!dp[i][j][k]) continue;
                if (i+1 < H) {
                    dp[i+1][j][k+A[i+1][j]-B[i+1][j]] = true;
                    dp[i+1][j][k-A[i+1][j]+B[i+1][j]] = true;
                }
                if (j+1 < W) {
                    dp[i][j+1][k+A[i][j+1]-B[i][j+1]] = true;
                    dp[i][j+1][k-A[i][j+1]+B[i][j+1]] = true;
                }
            }
        }
    }
    ll ans = INF;
    for (int k = 0; k <= 2*M; k++) {
        if (!dp[H-1][W-1][k]) continue;
        ans = min(ans, abs(M-k));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
