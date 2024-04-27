// https://atcoder.jp/contests/abc222/tasks/abc222_d
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    vector<vector<mint>> dp(N+1, vector<mint>(3002, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 3000; j++) {
            if (dp[i][j].val() == 0) continue;
            if (j <= b[i]) {
                dp[i+1][max(j, a[i])] += dp[i][j];
                dp[i+1][b[i]+1] -= dp[i][j];
            }
        }
        for (int j = 0; j <= 3000; j++) dp[i+1][j+1] += dp[i+1][j];
    }
    mint ans = 0;
    for (int j = 0; j <= 3000; j++) ans += dp.back()[j];
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
