// https://atcoder.jp/contests/abc132/tasks/abc132_e
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
vector<vector<int>> d;


void bfs(int s) {
    vector<queue<int>> Q(3);
    Q[0].push(s);

    while (!Q[0].empty() || !Q[1].empty() || !Q[2].empty()) {
        for (int k = 0; k < 3; k++) {
            int l = (k + 1) % 3;
            while (!Q[k].empty()) {
                int u = Q[k].front();
                Q[k].pop();
                for (int v : G[u]) {
                    if (d[l][v] != -1) continue;
                    d[l][v] = d[k][u] + (l == 0);
                    Q[l].push(v);
                }
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int k = 0; k < M; k++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;
    d.assign(3, vector<int>(N, -1));
    d[0][S] = 0;
    bfs(S);

    cout << d[0][T] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
