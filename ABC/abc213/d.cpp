#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> in, out;
vector<int> path;

void dfs(int u, int par, int &cur) {
    in[u] = cur;
    path.push_back(u);
    for (int v : G[u]) {
        if (v == par) continue;
        cur++;
        dfs(v, u, cur);
    }
    cur++;
    out[u] = cur;
    if (par != -1) path.push_back(par);
    return;
}

int main() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    for (int u = 0; u < N; u++) sort(G[u].begin(), G[u].end());

    in.assign(N, -1);
    out.assign(N, -1);

    int cur = 0;
    dfs(0, -1, cur);

    for (int u : path) cout << u+1 << " ";
    cout << endl;
}
