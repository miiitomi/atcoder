// https://atcoder.jp/contests/abc248/tasks/abc248_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint;


void solve() {
    ll N, P;
    cin >> N >> P;
    mint::set_mod(P);
    vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(N+10, vector<mint>(2, 0)));
    dp[0][0] = {0, 1};
    dp[0][1] = {1, 0};
    for (int i = 0; i < N-1; i++) {
        for (int k = 0; k <= N-1; k++) {
            dp[i+1][k][1] += dp[i][k][0];
            dp[i+1][k+1][0] += dp[i][k][0];
            dp[i+1][k][1] += dp[i][k][1];
            dp[i+1][k+1][1] += 3*dp[i][k][1];
            dp[i+1][k+2][0] += 2*dp[i][k][1];
        }
    }
    for (int k = 1; k <= N-1; k++) {
        cout << dp.back()[k][1].val() << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
