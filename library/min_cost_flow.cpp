#include <bits/stdc++.h>
using namespace std;

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

    T INF = 2e+9;  // TODO: update if needed.
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
    int N, M, F;
    cin >> N >> M >> F;

    MinCostFlowGraph<int> mcfg(N);

    for (int i = 0; i < M; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        mcfg.add_edge(u, v, c, d);
    }

    cout << mcfg.min_cost_flow(0, N-1, F) << endl;
}
