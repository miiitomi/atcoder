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

int N, M;
int to_id(int i, int j) {return i*M + j;}
pair<int,int> to_ij(int x) {return make_pair(x/M, x%M);}
vector<int> dx{1, 0, -1, 0}, dy{0, 1, 0, -1};
bool is_in(int i, int j) {return 0 <= i && i < N && 0 <= j && j < M;}


int main() {
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    MaxFlowGraph<int> mfg(N*M+2);
    int s = N*M, t = N*M + 1;
    vector<bool> is_edge(5*N*M, false);

    vector<vector<int>> c(N, vector<int>(M, -1));
    c[0][0] = 0;
    queue<pair<int,int>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        pair<int,int> p = Q.front();
        Q.pop();
        for (int k = 0; k < 2; k++) {
            int i = p.first + dx[k], j = p.second + dy[k];
            if (!is_in(i, j) || c[i][j] != -1) continue;
            c[i][j] = 1 - c[p.first][p.second];
            Q.push(make_pair(i, j));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '#') continue;
            int x = to_id(i, j);
            if (c[i][j] == 1) {
                mfg.add_edge(x, t, 1);
                continue;
            }
            mfg.add_edge(s, x, 1);
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k], b = j + dy[k];
                if (!is_in(a, b) || S[a][b] == '#') continue;
                int idx = mfg.add_edge(x, to_id(a, b), 1);
                is_edge[idx] = true;
            }
        }
    }

    int ans = mfg.max_flow(s, t);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x = to_id(i, j);
            for (auto &e : mfg.G[x]) {
                if (e.cap == 0 && e.id >= 0 && is_edge[e.id]) {
                    int y = e.to;
                    pair<int,int> p = to_ij(y);
                    int a = p.first, b = p.second;
                    if (i == a) {
                        if (j < b) {
                            S[i][j] = '>';
                            S[a][b] = '<';
                        } else {
                            S[a][b] = '>';
                            S[i][j] = '<';
                        }
                    } else {
                        if (i < a) {
                            S[i][j] = 'v';
                            S[a][b] = '^';
                        } else {
                            S[a][b] = 'v';
                            S[i][j] = '^';
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    for (string s : S) cout << s << endl;
}
