// https://atcoder.jp/contests/abc262/tasks/abc262_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = true;
        G[v][u] = true;
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
