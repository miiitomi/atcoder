#include <bits/stdc++.h>
using namespace std;

int INF = 1e+9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int> > > G(N);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    vector<int> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    Q.push(make_pair(0, 0));

    while(!Q.empty()) {
        pair<int, int> p = Q.top();
        int v = p.second;
        int d = p.first;
        Q.pop();
        
        if (dist[v] < d) continue;

        for (auto q : G[v]) {
            if (dist[q.first] > d + q.second) {
                dist[q.first] = d + q.second;
                Q.push(make_pair(dist[q.first], q.first));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
