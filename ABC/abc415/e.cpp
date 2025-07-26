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
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];
    vector<ll> P(H+W-1);
    for (int i = 0; i < H+W-1; i++) cin >> P[i];
    vector<vector<ll>> dp(H, vector<ll>(W));
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            ll ok = INF;
            if (i+1 < H) ok = min(ok, dp[i+1][j]);
            if (j+1 < W) ok = min(ok, dp[i][j+1]);
            if (i == H-1 && j == W-1) ok = 0;
            ll needs = P[i+j] + ok;
            if (A[i][j] >= needs) dp[i][j] = 0;
            else dp[i][j] = needs - A[i][j];
        }
    }
    cout << dp[0][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
