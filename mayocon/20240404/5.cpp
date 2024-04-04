// https://atcoder.jp/contests/abc175/tasks/abc175_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void chmax(ll &left, ll right) {if (left < right) left = right;}

void solve() {
    ll R, C, K;
    cin >> R >> C >> K;
    vector<vector<ll>> v(R, vector<ll>(C, 0));
    for (int i = 0; i < K; i++) {
        int r, c, w;
        cin >> r >> c >> w;
        r--;
        c--;
        v[r][c] = w;
    }

    vector<vector<vector<ll>>> dp(R, vector<vector<ll>>(C, vector<ll>(4, -INF)));
    dp[0][0][0] = 0;
    if (v[0][0] > 0) dp[0][0][1] = v[0][0];
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            for (int k = 0; k <= 3; k++) {
                if (dp[x][y][k] < 0) continue;
                if (x+1 <= R-1) {
                    chmax(dp[x+1][y][0], dp[x][y][k]);
                    if (v[x+1][y] > 0) chmax(dp[x+1][y][1], dp[x][y][k] + v[x+1][y]);
                }
                if (y+1 <= C-1) {
                    chmax(dp[x][y+1][k], dp[x][y][k]);
                    if (k <= 2 && v[x][y+1] > 0) chmax(dp[x][y+1][k+1], dp[x][y][k] + v[x][y+1]);
                }
            }
        }
    } 

    cout << *max_element(dp[R-1][C-1].begin(), dp[R-1][C-1].end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
