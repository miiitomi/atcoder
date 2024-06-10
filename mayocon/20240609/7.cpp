// https://atcoder.jp/contests/abc205/tasks/abc205_f
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

void solve() {
    int H, W, N;
    cin >> H >> W >> N;

    MaxFlowGraph<int> mfg(H + W + 2*N + 2);

    int s = H + W + 2*N, t = H + W + 2*N + 1;
    for (int l = 0; l < H; l++) mfg.add_edge(s, l, 1);
    for (int r = 0; r < W; r++) mfg.add_edge(H + r, t, 1);
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        mfg.add_edge(H+W+i, H+W+N+i, 1);
        for (int l = a; l <= c; l++) mfg.add_edge(l, H+W+i, 1);
        for (int r = b; r <= d; r++) mfg.add_edge(H+W+N+i, H+r, 1);
    }
    int ans = mfg.max_flow(s, t);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
