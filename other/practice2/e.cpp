#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct MinCostFlowGraph {
    struct Edge {
        int id;
        int to;
        T cap;
        T cost;
        int rev;

        Edge(int _id, int _to, T _cap, T _cost, int _rev): id(_id), to(_to), cap(_cap), cost(_cost), rev(_rev) {}
    };

    T INF = 2e+18;  // TODO: update if needed.
    int N;  // Number of verteces.
    int E;  // Number of edges (excluding the reverse edges for residual).
    vector<vector<Edge>> G;

    MinCostFlowGraph(int n) {
        N = n;
        E = 0;
        G.resize(N);
    }

    int add_edge(int from, int to, T cap, T cost) {
        G[from].push_back(Edge(E, to, cap, cost, G[to].size()));
        G[to].push_back(Edge(-1, from, 0, -cost, G[from].size()-1));
        E++;
        return E-1;
    }

    T min_cost_flow(int s, int t, T f) {
        T res = 0;
        vector<T> h(N, 0), dist(N, INF);
        vector<int> prev_v(N, -1), prev_e(N, -1);
        while (f > 0) {
            // Update potential h[v] by Dijkstra.
            priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;
            dist.assign(N, INF);
            dist[s] = 0;
            Q.push(make_pair(0, s));
            while (!Q.empty()) {
                pair<T, int> p = Q.top();
                Q.pop();
                int v = p.second;
                if (dist[v] < p.first) continue;
                for (int i = 0; i < (int)G[v].size(); i++) {
                    Edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prev_v[e.to] = v;
                        prev_e[e.to] = i;
                        Q.push(make_pair(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] == INF) return -1;
            for (int v = 0; v < N; v++) h[v] += dist[v];

            // Flow along the shortest path s-t.
            T d = f;
            for (int v = t; v != s; v = prev_v[v]) d = min(d, G[prev_v[v]][prev_e[v]].cap);
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prev_v[v]) {
                Edge &e = G[prev_v[v]][prev_e[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    ll mv = 1e+9;
    int V = 2*N + 2;
    int s = 2*N, t = 2*N+1;
    MinCostFlowGraph<ll> mcfg(V);

    mcfg.add_edge(s, t, 1e+9, mv);
    for (int i = 0; i < N; i++) {
        mcfg.add_edge(s, i, K, 0);
        mcfg.add_edge(N+i, t, K, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mcfg.add_edge(i, N+j, 1, mv - A[i][j]);
        }
    }

    ll res = mcfg.min_cost_flow(s, t, N*K);
    cout << mv*N*K - res << endl;

    vector<string> S(N, string(N, '.'));
    for (int v = 0; v < N; v++) {
        for (int i = 0; i < (int)mcfg.G[v].size(); i++) {
            auto &e = mcfg.G[v][i];
            if (e.id != -1 && e.to < s && e.cap == 0) {
                S[v][e.to - N] = 'X';
            }
        }
    }

    for (int i = 0; i < N; i++) cout << S[i] << endl;
}
