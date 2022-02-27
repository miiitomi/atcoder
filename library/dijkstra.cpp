// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M, r;
    cin >> N >> M >> r;

    vector<vector<pair<ll, ll>>> G(N);

    for (int i = 0; i < M; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(make_pair(t, d));
    }

    vector<ll> dist(N, INF);
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

    for (int v = 0; v < N; v++) {
        if (dist[v] == INF) cout << "INF" << endl;
        else cout << dist[v] << endl;
    }
}
