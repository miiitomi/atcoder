// https://atcoder.jp/contests/abc193/tasks/abc193_f
#include <bits/stdc++.h>
using namespace std;

int N;
bool is_in(int x, int y) {return 0 <= x && x < N && 0 <= y && y < N;}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
int to_int(int x, int y) {return x*N + y;}

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
    cin >> N;
    vector<string> c(N);
    for (int i = 0; i < N; i++) cin >> c[i];

    int s = N*N, t = N*N+1;
    MaxFlowGraph<int> mfg(N*N+2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool white = ((i+j)%2 == 0);
            int u = to_int(i, j);
            if (white) {
                if (c[i][j] == 'B') mfg.add_edge(s, u, 1e+6);
                if (c[i][j] == 'W') mfg.add_edge(u, t, 1e+6);
            } else {
                if (c[i][j] == 'W') mfg.add_edge(s, u, 1e+6);
                if (c[i][j] == 'B') mfg.add_edge(u, t, 1e+6);
            }
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y)) continue;
                int v = to_int(x, y);
                mfg.add_edge(u, v, 1);
            }
        }
    }

    cout << 2*N*(N-1) - mfg.max_flow(s, t) << endl;
}
