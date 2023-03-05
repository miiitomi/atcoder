#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<set<int>> &G, vector<bool> &done) {
    for (int v : G[u]) {
        if (!done[v]) {
            done[v] = true;
            dfs(v, G, done);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
    }

    int ans = 0;
    for (int s = 0; s < N; s++) {
        vector<bool> done(N, false);
        done[s] = true;
        dfs(s, G, done);
        for (int u = 0; u < N; u++) {
            if (u != s && done[u] && !G[s].count(u)) ans++;
        }
    }

    cout << ans << endl;
}
