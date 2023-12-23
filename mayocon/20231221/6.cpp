// https://atcoder.jp/contests/abc251/tasks/abc251_f
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
vector<int> d;

void dfs(int v, vector<int> &T1) {
    for (int w : G[v]) {
        if (T1[w] != -1) continue;
        T1[w] = v;
        dfs(w, T1);
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int k = 0; k < M; k++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> v(N), T1(N, -1), T2(N, -1);
    T1[0] = 0;
    dfs(0, T1);

    vector<bool> reached(N, false);
    reached[0] = true;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int w : G[v]) {
            if (reached[w]) continue;
            reached[w] = true;
            T2[w] = v;
            Q.push(w);
        }
    }

    for (int u = 1; u < N; u++) cout << T1[u]+1 << " " << u+1 << "\n";
    for (int u = 1; u < N; u++) cout << T2[u]+1 << " " << u+1 << "\n";
}
