// https://atcoder.jp/contests/abc264/tasks/abc264_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18;
void chmin(ll &l, ll r) {if (l > r) l = r;}

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<ll> R(H), C(W);
    for (int i = 0; i < H; i++) cin >> R[i];
    for (int i = 0; i < W; i++) cin >> C[i];

    vector<vector<ll>> A(H, vector<ll>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '1') A[i][j] = 1;
        }
    }

    vector<vector<vector<vector<ll>>>> dp(H, vector<vector<vector<ll>>>(W, vector<vector<ll>>(2, vector<ll>(2, INF))));
    dp[0][0][0][0] = 0;
    dp[0][0][1][0] = R[0];
    dp[0][0][0][1] = C[0];
    dp[0][0][1][1] = R[0]+C[0];

    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (x+1 < H) {
                        if (((A[x][y]^i)^j) == (A[x+1][y]^j)) chmin(dp[x+1][y][0][j], dp[x][y][i][j]);
                        else chmin(dp[x+1][y][1][j], dp[x][y][i][j] + R[x+1]);
                    }
                    if (y+1 < W) {
                        if (((A[x][y]^i)^j) == (A[x][y+1]^i)) chmin(dp[x][y+1][i][0], dp[x][y][i][j]);
                        else chmin(dp[x][y+1][i][1], dp[x][y][i][j] + C[y+1]);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) chmin(ans, dp[H-1][W-1][i][j]);
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
