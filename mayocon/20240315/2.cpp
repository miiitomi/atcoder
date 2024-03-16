// https://atcoder.jp/contests/abc262/tasks/abc262_b
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int ans = 0;
    for (int a = 0; a < N; a++) {
        for (int b = a+1; b < N; b++) {
            for (int c = b+1; c < N; c++) {
                if (G[a][b] && G[b][c] && G[c][a]) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
