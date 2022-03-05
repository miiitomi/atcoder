#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (H[u] < H[v]) swap(u, v);
        G[u].push_back(make_pair(v, 0));
        G[v].push_back(make_pair(u, H[u] - H[v]));
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push(make_pair(dist[0], 0));

    while (!Q.empty()) {
        int v = Q.top().second;
        ll d_v = Q.top().first;
        Q.pop();
        if (dist[v] != d_v) continue;

        for (pair<ll, int> p : G[v]) {
            if (dist[p.first] > dist[v] + p.second) {
                dist[p.first] = dist[v] + p.second;
                Q.push(make_pair(dist[p.first], p.first));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        dist[i] = H[0] - H[i] - dist[i];
    }
    cout << *max_element(dist.begin(), dist.end()) << endl;
}
