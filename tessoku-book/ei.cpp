#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int N, vector<vector<int>> &G, vector<bool> &done, vector<int> &path) {
    done[v] = true;

    if (v == N-1) {
        path.push_back(v);
        return;
    }

    for (int w : G[v]) {
        if (done[w]) continue;

        dfs(w, N, G, done, path);
        if (done[N-1]) {
            path.push_back(v);
            return;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> done(N, false);
    vector<int> path;
    dfs(0, N, G, done, path);

    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1;
        if (i == 0) cout << endl;
        else cout << " ";
    }
}
