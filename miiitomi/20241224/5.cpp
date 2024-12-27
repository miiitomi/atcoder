// https://atcoder.jp/contests/abc283/tasks/abc283_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1e+9;
const ll MOD = 998244353;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    vector<vector<int>> dp(H, vector<int>(8, INF));
    for (int h = 0; h+1 < H; h++) {
        for (uint k = 0; k < 8; k++) {
            vector<int> s(W, -1), t = A[h], u = A[h+1];
            if (h > 0) {
                s = A[h-1];
                if (k & 1) for (int j = 0; j < W; j++) s[j] ^= 1;
            }
            if (k & 2) for (int j = 0; j < W; j++) t[j] ^= 1;
            if (k & 4) for (int j = 0; j < W; j++) u[j] ^= 1;
            bool ok = true;
            for (int j = 0; j < W; j++) {
                bool tmp = (s[j] == t[j]) || (t[j] == u[j]);
                if (j-1 >= 0 && t[j] == t[j-1]) tmp = true;
                if (j+1 < W && t[j] == t[j+1]) tmp = true;
                if (!tmp) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            if (h == 0) {
                dp[h+1][k] = popcount(k);
                continue;
            }
            for (int l = 0; l < 8; l++) {
                if ((l >> 1) == (int)(k & 3)) {
                    dp[h+1][k] = min(dp[h+1][k], dp[h][l] + (bool)(k & 4));
                }
            }
        }
    }
    int ans = INF;
    for (int k = 0; k < 8; k++) {
        if (dp[H-1][k] == INF) continue;
        vector<int> s = A[H-2], t = A[H-1];
        if (k & 2) for (int j = 0; j < W; j++) s[j] ^= 1;
        if (k & 4) for (int j = 0; j < W; j++) t[j] ^= 1;
        bool ok = true;
        for (int j = 0; j < W; j++) {
            bool tmp = (s[j] == t[j]);
            if (j-1 >= 0 && t[j] == t[j-1]) tmp = true;
            if (j+1 < W && t[j] == t[j+1]) tmp = true;
            if (!tmp) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(ans, dp[H-1][k]);
        }
    }
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
