// https://atcoder.jp/contests/abc201/tasks/abc201_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    vector<vector<ll>> dp(H, vector<ll>(W, -INF));
    dp[H-1][W-1] = 0;
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (i+1 <= H-1) dp[i][j] = max(dp[i][j], -dp[i+1][j] + 2*(A[i+1][j]=='+')-1);
            if (j+1 <= W-1) dp[i][j] = max(dp[i][j], -dp[i][j+1] + 2*(A[i][j+1]=='+')-1);
        }
    }
    if (dp[0][0] > 0) cout << "Takahashi\n";
    else if (dp[0][0] == 0) cout << "Draw\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
