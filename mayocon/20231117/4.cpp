// https://atcoder.jp/contests/abc320/tasks/abc320_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e+18;

struct Edge {
    int to;
    ll x;
    ll y;
    Edge(int to, ll x, ll y): to(to), x(x), y(y) {}
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll x, y;
        cin >> a >> b >> x >> y;
        a--;
        b--;
        G[a].emplace_back(b, x, y);
        G[b].emplace_back(a, -x, -y);
    }

    vector<ll> X(N, INF), Y(N, INF);
    X[0] = 0;
    Y[0] = 0;
    queue<int> Q;
    Q.push(0);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto &e : G[v]) {
            if (X[e.to] != INF) continue;
            X[e.to] = X[v] + e.x;
            Y[e.to] = Y[v] + e.y;
            Q.push(e.to);
        }
    }

    for (int i = 0; i < N; i++) {
        if (X[i] == INF) cout << "undecidable" << endl;
        else cout << X[i] << " " << Y[i] << endl;
    }
}
