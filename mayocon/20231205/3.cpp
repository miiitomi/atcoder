// https://atcoder.jp/contests/abc270/tasks/abc270_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> par(N, -1);
    par[X] = X;
    queue<int> Q;
    Q.push(X);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (par[v] != -1) continue;
            par[v] = u;
            Q.push(v);
        }
    }

    vector<int> path;
    int v = Y;
    path.push_back(v);
    while (v != X) {
        v = par[v];
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    for (int u : path) cout << u + 1 << " ";
    cout << endl;
}
