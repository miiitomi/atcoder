#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct MaxFlowGraph {
    struct Edge {
        int id;  // Edge id. If it is a reverse edge, set -1.
        int to;  // Vertex id taht this edge is toward.
        T cap;  // Capacity of this edge.
        int rev; // Reverse edge's position in G[to].

        Edge(int _id, int _to, T _cap, int _rev): id(_id), to(_to), cap(_cap), rev(_rev) {}
    };

    T INF = 2e+9; // TODO: Update if needed.
    int N;  // Number of verteces.
    int E;  // Number of edges (excluding the reverse edges for residual).
    vector<vector<Edge>> G;
    vector<int> dist;
    vector<int> iter;

    MaxFlowGraph(int n) {
        N = n;
        E = 0;
        G.resize(N);
    }

    int add_edge(int from, int to, T cap) {
        // Set edge from 'from' to 'to' with capacity 'cap'. Return the edge ID.
        G[from].push_back(Edge(E, to, cap, G[to].size()));
        G[to].push_back(Edge(-1, from, 0, G[from].size()-1));
        E++;
        return E-1;
    }

    void bfs(int s) {
        // Compute min distance of each v from s by BFS.
        dist.assign(N, -1);
        dist[s] = 0;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (Edge &e : G[v]) {
                if (e.cap > 0 && dist[e.to] < 0) {
                    dist[e.to] = dist[v] + 1;
                    Q.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f) {
        // Flow v to t with max flow f recursively by DFS.
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && dist[v] < dist[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        // Compute maximum flow via Dinic's algorithm. O(|E||V|^2) in worst case, but faster in many practical cases.
        T flow = 0;
        while (true) {
            bfs(s);
            if (dist[t] < 0) return flow;
            iter.assign(N, 0);
            T f = dfs(s, t, INF);
            while (f > 0) {
                flow += f;
                f = dfs(s, t, INF);
            }
        }
    }
};

int main() {
    int N, M, ans = 0;
    cin >> N >> M;
    MaxFlowGraph<int> mfg(N+2);
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        if (p >= 0) {
            ans += p;
            mfg.add_edge(0, i, p);
        } else {
            mfg.add_edge(i, N+1, abs(p));
        }
    }
    while (M--) {
        int a, b;
        cin >> a >> b;
        mfg.add_edge(a, b, 1e+6);
    }

    cout << ans - mfg.max_flow(0, N+1) << endl;
}
