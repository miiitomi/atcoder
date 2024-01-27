// https://atcoder.jp/contests/abc332/tasks/abc332_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, D;
    cin >> N >> D;
    double m = 0.0;
    vector<int> W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        m += W[i];
    }
    m /= D;

    vector<vector<double>> dp((1 << N), vector<double>(D+1, 1e+18));
    dp[0][0] = 0;
    for (int s = 1; s < (1 << N); s++) {
        dp[s][1] = 0;
        for (int j = 0; j < N; j++) if (s & (1 << j)) dp[s][1] += W[j];
        dp[s][1] = (dp[s][1] - m)*(dp[s][1] - m);
        for (int d = 1; d <= D; d++) {
            for (int t = s; t > 0; t = (t-1) & s) {
                dp[s][d] = min(dp[s][d], dp[s-t][d-1] + dp[t][1]);
            }
        }
    }

    cout << dp[(1 << N) - 1][D] / D << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
