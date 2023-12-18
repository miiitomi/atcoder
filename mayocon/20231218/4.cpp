// https://atcoder.jp/contests/abc168/tasks/abc168_d
#include <bits/stdc++.h>
using namespace std;

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

    vector<pair<int,int>> d(N, make_pair(-1, -1));
    d[0] = make_pair(0, -1);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v].first != -1) continue;
            d[v].first = d[u].first + 1;
            d[v].second = u;
            Q.push(v);
        }
    }

    cout << "Yes" << endl;
    for (int u = 1; u < N; u++) cout << d[u].second + 1 << "\n";
}
