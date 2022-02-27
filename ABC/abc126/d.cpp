#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<pair<int, int>>> &G, vector<int> &colors) {
    for (auto p : G[v]) {
        if (colors[p.first] != -1) continue;

        if (p.second % 2 == 0) {
            colors[p.first] = colors[v];
        } else {
            colors[p.first] = 1 - colors[v];
        }

        dfs(p.first, G, colors);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    vector<int> colors(N, -1);
    colors[0] = 0;
    dfs(0, G, colors);

    for (int i = 0; i < N; i++) cout << colors[i] << endl;
}
