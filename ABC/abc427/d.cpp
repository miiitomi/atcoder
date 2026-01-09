#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }
    vector<vector<bool>> dp(2*K+1, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        dp[2*K][i] = (S[i] == 'A');
    }
    for (int k = 2*K-1; k >= 0; k--) {
        for (int u = 0; u < N; u++) {
            dp[k][u] = (k % 2);
            for (int v: G[u]) {
                if (k % 2) {
                    if (!dp[k+1][v]) dp[k][u] = false;
                } else {
                    if (dp[k+1][v]) dp[k][u] = true;
                }
            }
        }
    }

    if (dp[0][0]) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
