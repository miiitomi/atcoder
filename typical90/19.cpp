// https://atcoder.jp/contests/typical90/tasks/typical90_s
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(2*N);
    for (int i = 0; i < 2*N; i++) cin >> A[i];
    vector<vector<ll>> dp(2*N+1, vector<ll>(2*N+1, INF));
    for (int i = 0; i <= 2*N; i++) dp[i][i] = 0;
    for (int k = 2; k <= 2*N; k += 2) {
        for (int l = 0; l+k <= 2*N; l++) {
            int r = l+k;
            dp[l][r] = abs(A[l]-A[r-1]) + dp[l+1][r-1];
            for (int m = l+2; m < r; m += 2) {
                dp[l][r] = min(dp[l][r], dp[l][m]+dp[m][r]);
            }
        }
    }
    cout << dp[0][2*N] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
