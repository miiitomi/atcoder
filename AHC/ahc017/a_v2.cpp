// 原点からの距離で全点を並び替える.
// 各辺を、原点からの距離で並び替える.
// 並び替えた辺から、良い感じの感覚で工事を行う.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;    
}

int main() {
    int N, M, D, K;
    cin >> N >> M >> D >> K;

    vector<vector<pair<int, int>>> G(N);
    vector<vector<int>> E(M, vector<int>(3, 0));

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));

        E[i][0] = u;
        E[i][1] = v;
        E[i][2] = w;
    }

    vector<ll> dist(N, INF);
    int r = 0;
    dist[r] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, r));

    while (!Q.empty()) {
        ll d = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dist[v] < d) continue;

        for (auto p : G[v]) {
            if (dist[v] + p.second < dist[p.first]) {
                dist[p.first] = dist[v] + p.second;
                pair<ll, ll> q = make_pair(dist[p.first], p.first);
                Q.push(q);
            }
        }
    }

    vector<pair<int, int>> Edges(M);
    for (int i = 0; i < M; i++) {
        int d = 1e+9;
        int u = E[i][0];
        int v = E[i][1];
        d = min(dist[u], dist[v]);
        Edges[i].first = d;
        Edges[i].second = i;
    }

    sort(Edges.begin(), Edges.end());

    int L;
    if (M / K == 0) L = M / K;
    else L = (M / K) + 1;

    int day = 1;
    for (int i = 0; i < M; i++) {
        Edges[i].first = day;
        day++;
        if (day == L + 1) day = 1;
    }

    sort(Edges.begin(), Edges.end(), cmp);
    for (int i = 0; i < M; i++) {
        cout << Edges[i].first;
        if (i == M-1) cout << endl;
        else cout << " ";
    }
}
