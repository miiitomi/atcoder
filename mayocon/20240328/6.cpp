// https://atcoder.jp/contests/abc264/tasks/abc264_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmin(ll &x, ll y) {if (x > y) x = y;}

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<ll> R(H), C(W);
    for (int i = 0; i < H; i++) cin >> R[i];
    for (int i = 0; i < W; i++) cin >> C[i];
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    vector<vector<vector<ll>>> dp(H, vector<vector<ll>>(W, vector<ll>(4, INF)));
    dp[0][0][0] = 0;
    dp[0][0][1] = R[0];
    dp[0][0][2] = C[0];
    dp[0][0][3] = R[0] + C[0];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j+1 <= W-1) {
                if (A[i][j] == A[i][j+1]) {
                    chmin(dp[i][j+1][0], dp[i][j][0]);
                    chmin(dp[i][j+1][1], dp[i][j][1]);
                    chmin(dp[i][j+1][2], dp[i][j][2] + C[j+1]);
                    chmin(dp[i][j+1][3], dp[i][j][3] + C[j+1]);
                } else {
                    chmin(dp[i][j+1][2], dp[i][j][0] + C[j+1]);
                    chmin(dp[i][j+1][3], dp[i][j][1] + C[j+1]);
                    chmin(dp[i][j+1][0], dp[i][j][2]);
                    chmin(dp[i][j+1][1], dp[i][j][3]);
                }
            }
            if (i+1 <= H-1) {
                if (A[i][j] == A[i+1][j]) {
                    chmin(dp[i+1][j][0], dp[i][j][0]);
                    chmin(dp[i+1][j][1], dp[i][j][1] + R[i+1]);
                    chmin(dp[i+1][j][2], dp[i][j][2]);
                    chmin(dp[i+1][j][3], dp[i][j][3] + R[i+1]);
                } else {
                    chmin(dp[i+1][j][1], dp[i][j][0] + R[i+1]);
                    chmin(dp[i+1][j][0], dp[i][j][1]);
                    chmin(dp[i+1][j][3], dp[i][j][2] + R[i+1]);
                    chmin(dp[i+1][j][2] ,dp[i][j][3]);
                }
            }
        }
    }

    ll ans = *min_element(dp[H-1][W-1].begin(), dp[H-1][W-1].end());
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
