// https://atcoder.jp/contests/abc218/tasks/abc218_f
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> G;

int bfs(int ng, vector<bool> &used) {
    vector<int> d(N, 1e+9);
    d[0] = 0;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto p : G[v]) {
            if (p.first == ng || d[p.second] < 1e+9) continue;
            d[p.second] = d[v] + 1;
            Q.push(p.second);
            if (ng == -1) used[p.first] = true;
        }
    }
    return d[N-1];
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(make_pair(i, v));
    }

    vector<bool> used(M, false);
    int ans = bfs(-1, used);

    if (ans == 1e+9) {
        for (int i = 0; i < M; i++) {
            cout << -1 << endl;
        }
        return 0;
    }

    for (int i = 0; i < M; i++) {
        if (used[i]) {
            int tmp = bfs(i, used);
            if (tmp == 1e+9) cout << -1 << endl;
            else cout << tmp << endl;
        } else cout << ans << endl;
    }
}
