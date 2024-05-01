// https://atcoder.jp/contests/abc251/tasks/abc251_f
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;

vector<pair<int,int>> T1, T2;

void dfs(int u, vector<bool> &reached) {
    reached[u] = true;
    for (int v : G[u]) {
        if (reached[v]) continue;
        T1.push_back(make_pair(u, v));
        dfs(v, reached);
    }
}

void bfs() {
    queue<int> Q;
    Q.push(0);
    vector<bool> reached(N, false);
    reached[0] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (reached[v]) continue;
            reached[v] = true;
            T2.push_back(make_pair(u, v));
            Q.push(v);
        }
    }
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int m = 0; m < M; m++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int u = 0; u < N; u++) if ((int)G[u].size() >= 2) sort(G[u].begin(), G[u].end());
    vector<bool> reached(N, false);
    dfs(0, reached);
    bfs();

    for (auto &p : T1) cout << p.first+1 << " " << p.second+1 << "\n";
    for (auto &p : T2) cout << p.first+1 << " " << p.second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
