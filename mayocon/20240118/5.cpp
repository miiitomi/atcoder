// https://atcoder.jp/contests/abc289/tasks/abc289_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (C[0] == C[N-1]) {
        cout << -1 << "\n";
        return;
    }

    vector<vector<int>> H(N*N);
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (C[u] == C[v]) continue;
            int s = N*u + v;
            for (int x : G[u]) {
                for (int y : G[v]) {
                    if (C[x] == C[y]) continue;
                    int t = N*x + y;
                    H[s].push_back(t);
                }
            }
        }
    }

    vector<int> d(N*N, -1);
    d[N*0+N-1] = 0;
    queue<int> Q;
    Q.push(N*0+N-1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : H[u]) {
            if (d[v] >= 0) continue;
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }

    cout << d[(N-1)*N+0] << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
