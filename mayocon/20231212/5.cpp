// https://atcoder.jp/contests/abc252/tasks/abc252_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int id, to;
    ll cost;

    Edge(int id, int to, ll cost): id(id), to(to), cost(cost) {}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].emplace_back(Edge(i+1, v, c));
        G[v].emplace_back(Edge(i+1, u, c));
    }

    vector<ll> d(N, 1e+18);
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> Q;
    d[0] = 0;
    Q.push(make_pair(0, make_pair(0, -1)));
    vector<int> ans;

    while (!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        ll dist = p.first;
        int u = p.second.first;
        int id = p.second.second;

        if (d[u] != dist) continue;
        if (id != -1) ans.push_back(id);

        for (auto q : G[u]) {
            int v = q.to;
            ll c = q.cost;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                Q.push(make_pair(d[v], make_pair(v, q.id)));
            }
        }
    }

    for (int i : ans) cout << i <<  " ";
    cout << endl;
}
