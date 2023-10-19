// https://atcoder.jp/contests/abc218/tasks/abc218_f
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int,int>>> G;

int bfs(int ng, set<int> &S) {
    queue<int> Q;
    Q.push(0);
    vector<int> d(N, -1);
    d[0] = 0;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto p : G[v]) {
            if (p.second == ng || d[p.first] != -1) continue;
            d[p.first] = d[v] + 1;
            Q.push(p.first);
            if (ng == -1) S.insert(p.second);
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
        G[u].push_back(make_pair(v, i));
    }

    set<int> S;
    int min_v = bfs(-1, S);

    if (min_v == -1) {
        for (int i = 0; i < M; i++) cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < M; i++) {
        if (!S.count(i)) cout << min_v << endl;
        else cout << bfs(i, S) << endl;
    }
}
