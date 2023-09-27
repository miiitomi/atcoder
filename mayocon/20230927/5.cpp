// https://atcoder.jp/contests/abc252/tasks/abc252_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e+18;

struct Edge {
    int idx;
    int to;
    ll w;

    Edge(int idx, int to, int w) : idx(idx), to(to), w(w) {}
};


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        G[a].push_back(Edge(i, b, w));
        G[b].push_back(Edge(i, a, w));
    }

    vector<int> V;
    V.reserve(N);

    vector<pair<ll, int>> d(N, make_pair(INF, -1));
    d[0] = make_pair(0, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        auto p = Q.top();
        ll dist = p.first;
        int v = p.second;
        Q.pop();

        if (dist != d[v].first) continue;

        if (d[v].second != -1) V.push_back(d[v].second);

        for (auto &e : G[v]) {
            if (d[e.to].first > d[v].first + e.w) {
                d[e.to].first = d[v].first + e.w;
                d[e.to].second = e.idx;
                Q.push(make_pair(d[e.to].first, e.to));
            }
        }
    }

    for (int v : V) cout << 1 + v << " ";
    cout << endl;
}
