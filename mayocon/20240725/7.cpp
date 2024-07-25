// https://atcoder.jp/contests/abc325/tasks/abc325_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll K;
    string S;
    cin >> S >> K;
    ll N = S.size();

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));
    for (int i = 0; i <= N; i++) {
        dp[i][i] = 0;
        if (i < N) dp[i][i+1] = 1;
    }
    for (int k = 2; k <= N; k++) {
        for (int l = 0; l + k <= N; l++) {
            int r = l + k;
            dp[l][r] = r - l;
            for (int m = l+1; m < r; m++) dp[l][r] = min(dp[l][r], dp[l][m]+dp[m][r]);
            if (S[l] == 'o') {
                for (int m = l+1; m < r; m++) {
                    if (S[m] == 'f' && dp[l+1][m] == 0) {
                        dp[l][r] = min(dp[l][r], max(0LL, dp[m+1][r]-K));
                    }
                }
            }
        }
    }
    cout << dp[0][N] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
