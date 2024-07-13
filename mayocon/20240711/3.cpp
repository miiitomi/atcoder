// https://atcoder.jp/contests/abc232/tasks/abc232_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++) cin >> C[i];

    vector<vector<int>> dp(H, vector<int>(W, 1));
    for (int x = H-1; x >= 0; x--) {
        for (int y = W-1; y >= 0; y--) {
            if (C[x][y] == '#') continue;
            if (x > 0 && C[x-1][y]=='.') dp[x-1][y] = max(dp[x-1][y], dp[x][y]+1);
            if (y > 0 && C[x][y-1]=='.') dp[x][y-1] = max(dp[x][y-1], dp[x][y]+1);
        }
    }

    int ans = dp[0][0];
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
