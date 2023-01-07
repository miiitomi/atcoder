#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &G, vector<bool> &done) {
    done[v] = true;

    for (int w : G[v]) {
        if (!done[w]) {
            dfs(w, G, done);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> done(N, false);
    int ans = 0;

    for (int v = 0; v < N; v++) {
        if (!done[v]) {
            ans++;
            dfs(v, G, done);
        }
    }

    cout << ans << endl;
}
