// https://atcoder.jp/contests/abc210/tasks/abc210_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H, W, C;
const ll INF = 1e+18;

ll solve(vector<vector<ll>> &A) {
    ll ans = INF;
    vector<vector<ll>> dp(H, vector<ll>(W, INF));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + C);
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + C);
            ans = min(ans, dp[i][j] + A[i][j]);
            dp[i][j] = min(dp[i][j], A[i][j]);
        }
    }

    return ans;
}

int main() {
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    ll ans = solve(A);
    for (int i = 0; i < H; i++) reverse(A[i].begin(), A[i].end());
    ans = min(ans, solve(A));
    cout << ans << endl;
}
