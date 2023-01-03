// A62

#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int> > &G, vector<bool> &done) {
    done[v] = true;

    for (int w: G[v]) {
        if (!done[w]) {
            dfs(w, G, done);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> done(N, false);
    dfs(0, G, done);

    for (int v = 0; v < N; v++) {
        if (!done[v]) {
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }

    cout << "The graph is connected." << endl;
}
