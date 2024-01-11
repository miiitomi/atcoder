// https://atcoder.jp/contests/abc070/tasks/abc070_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<vector<pair<ll, ll>>> G(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        G[u].push_back(make_pair(v, x));
        G[v].push_back(make_pair(u, x));
    }

    int Q, s;
    cin >> Q >> s;
    s--;
    vector<ll> d(N, 1e+18);
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;
        ll dist = p.first;
        if (dist != d[u]) continue;
        for (auto e : G[u]) {
            int v = e.first;
            ll c = e.second;
            if (d[u] + c < d[v]) {
                d[v] = d[u] + c;
                pq.push(make_pair(d[v], v));
            }
        }
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << d[x] + d[y] << "\n";
    }
}
