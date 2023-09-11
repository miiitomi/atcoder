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

    vector<vector<int>> V(N*N);
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (C[u] == C[v]) {
                if ((u == 0 && v == N-1) || (u == N-1 && v == 0)) continue;
            }

            for (int x : G[u]) {
                for (int y : G[v]) {
                    if (C[x] == C[y]) continue;
                    V[N*u+v].push_back(N*x+y);
                }
            }
        }
    }

    vector<int> reached(N*N, -1);
    reached[N*0+N-1] = 0;
    queue<int> Q;
    Q.push(N*0+N-1);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : V[v]) {
            if (reached[w] == -1) {
                reached[w] = reached[v] + 1;
                Q.push(w);
            }
        }
    }

    cout << reached[N*(N-1) + 0] << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
