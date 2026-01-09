#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &G, vector<bool> &reached) {
    for (int v: G[u]) {
        if (reached[v]) continue;
        reached[v] = true;
        dfs(v, G, reached);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[y].push_back(x);
    }
    vector<bool> reached(N, false);
    int Q;
    cin >> Q;
    while (Q--) {
        int k, v;
        cin >> k >> v;
        v--;
        if (k == 1) {
            if (!reached[v]) {
                reached[v] = true;
                dfs(v, G, reached);
            }
        } else {
            if (reached[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
