#include <bits/stdc++.h>
using namespace std;

int INF = (int)1e+9;

void dfs(int u, vector<vector<int>> &G, vector<int> &d) {
    for (int v : G[u]) {
        if (d[v] == INF) {
            d[v] = d[u] + 1;
            dfs(v, G, d);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int u = 0;
    while ((int)G[u].size() != 1) u++;
    u = *G[u].begin();

    vector<int> d(N, INF);
    d[u] = 0;

    dfs(u, G, d);

    vector<int> L;
    for (int u = 0; u < N; u++) {
        if (d[u] % 3 == 0) {
            L.push_back((int)G[u].size());
        }
    }

    sort(L.begin(), L.end());

    for (int l : L) {
        cout << l << " ";
    }
    cout << endl;
}
