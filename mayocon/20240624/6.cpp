// https://atcoder.jp/contests/abc260/tasks/abc260_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int S, T, M;
    cin >> S >> T >> M;
    vector<vector<int>> G(S);
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        v -= S;
        G[u].push_back(v);
    }

    vector<vector<int>> dp(T, vector<int>(T, -1));
    for (int u = 0; u < S; u++) {
        sort(G[u].begin(), G[u].end());
        for (int i = 0; i < (int)G[u].size(); i++) {
            for (int j = i+1; j < (int)G[u].size(); j++) {
                int v1 = G[u][i], v2 = G[u][j];
                if (dp[v1][v2] != -1) {
                    cout << dp[v1][v2]+1 << " " << S+v1+1 << " " << u+1 << " " << S+v2+1 << endl;
                    return;
                } else {
                    dp[v1][v2] = u;
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
