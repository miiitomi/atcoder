// https://atcoder.jp/contests/abc210/tasks/abc210_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e+18;
ll H, W, C;
ll ans = INF;

void f(vector<vector<ll>> A) {
    vector<vector<ll>> dp(H, vector<ll>(W, INF));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = min(ans, dp[i][j] + A[i][j] + (i+j) * C);
            dp[i][j] = min(dp[i][j], A[i][j] - (i+j)*C);
            if (i < H-1) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if (j < W-1) dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
        }
    }
}

void solve() {
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    f(A);
    for (int i = 0; i < H; i++) reverse(A[i].begin(), A[i].end());
    f(A);
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
