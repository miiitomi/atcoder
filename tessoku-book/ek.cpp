#include <bits/stdc++.h>
using namespace std;

int INF = 1e+9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    vector<int> dist(N, INF);
    vector<int> before(N, -1);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        int d = p.first;
        int v = p.second;

        if (dist[v] < d) continue;

        for (auto q : G[v]) {
            if (dist[q.first] > d + q.second) {
                dist[q.first] = d + q.second;
                before[q.first] = v;
                Q.push(make_pair(dist[q.first], q.first));
            }
        }
    }

    vector<int> V;
    V.push_back(N-1);
    int now = N-1;
    while (now != 0) {
        now = before[now];
        V.push_back(now);
    }

    for (int i = (int)V.size() - 1; i >= 0; i--) {
        cout << V[i] + 1;
        if (i == 0) cout << endl;
        else cout << " ";
    }
}
