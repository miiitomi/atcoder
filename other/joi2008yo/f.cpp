#include <bits/stdc++.h>
using namespace std;

void dijkstra(int a, int b, vector<vector<pair<int, int>>> &G, int N) {
    vector<int> dist(N, 1e9);
    dist[a] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, a));

    while (!Q.empty()) {
        int v = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if (dist[v] < d) continue;

        for (auto p : G[v]) {
            if (dist[p.first] > dist[v] + p.second) {
                dist[p.first] = dist[v] + p.second;
                Q.push(make_pair(dist[p.first], p.first));
            }
        }
    }

    if (dist[b] != 1e9) cout << dist[b] << endl;
    else cout << -1 << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<pair<int, int>>> G(N);
    for (int k = 0; k < K; k++) {
        int o;
        cin >> o;
        if (o == 0) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            dijkstra(a, b, G, N);
        } else {
            int c, d, e;
            cin >> c >> d >> e;
            c--;
            d--;
            G[c].push_back(make_pair(d, e));
            G[d].push_back(make_pair(c, e));
        }
    }
}
