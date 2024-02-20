// https://atcoder.jp/contests/abc314/tasks/abc314_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N), P(N);
    vector<vector<int>> S(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> P[i];
        S[i].resize(P[i]);
        for (int j = 0; j < P[i]; j++) cin >> S[i][j];
    }

    vector<double> dp(M+1, 1e+18);
    dp[0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            double tmp = 0;
            int z = 0;
            for (int k = 0; k < P[j]; k++) {
                if (S[j][k] == 0) z++;
                else tmp += dp[max(0, i - S[j][k])];
            }
            double x = (P[j]*C[j] + tmp) / (P[j] - z);
            dp[i] = min(dp[i], x);
        }
    }

    cout << dp[M] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
