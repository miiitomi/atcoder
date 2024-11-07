// https://atcoder.jp/contests/abc217/tasks/abc217_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j-1] + (j - (i-1)/M) * dp[i-1][j];
        }
    }
    for (int k = 1; k <= N; k++) cout << dp[N][k].val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
