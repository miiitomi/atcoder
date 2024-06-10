// https://atcoder.jp/contests/abc203/tasks/abc203_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N+1, 0), f(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 1; i <= N; i++) f[i] = -1 + distance(A.begin(), lower_bound(A.begin(), A.end(), A[i]/2+1));
    vector<vector<int>> dp(N+1, vector<int>(31, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 30; j++) {
            dp[i][j] = dp[i-1][j] + 1;
            if (j > 0) dp[i][j] = min(dp[i][j], dp[f[i]][j-1]);
        }
    }

    for (int j = 0; j <= 30; j++) {
        if (dp[N][j] <= K) {
            cout << j << " " << dp[N][j] << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
