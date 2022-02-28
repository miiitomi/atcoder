// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == INF) cout << "INF";
            else cout << dp[i][j];
            if (j < N-1) cout << " ";
            else cout << endl;
        }
    }
}
