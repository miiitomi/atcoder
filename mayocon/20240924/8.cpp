// https://atcoder.jp/contests/abc274/tasks/abc274_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+9;
const ll MOD = 998244353;

template<typename T>
struct MaxFlowGraph {
    struct Edge {
        int id;  // Edge id. If it is a reverse edge, set -1.
        int to;  // Vertex id taht this edge is toward.
        T cap;  // Capacity of this edge.
        int rev; // Reverse edge's position in G[to].

        Edge(int _id, int _to, T _cap, int _rev): id(_id), to(_to), cap(_cap), rev(_rev) {}
    };

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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    int N = 2*H*W + 2, s = 2*H*W, t = 2*H*W+1;
    MaxFlowGraph<ll> mfg(N);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            int x = 2*(i*W+j), y = 2*(i*W+j) + 1;
            mfg.add_edge(s, x, 1);
            mfg.add_edge(y, t, 1);
            int a = i, b = j;
            while (a >= 1 && S[a-1][j] == '.') a--;
            while (b >= 1 && S[i][b-1] == '.') b--;
            x = 2*(W*a+j);
            y = 2*(W*i+b) + 1;
            mfg.add_edge(x, y, INF);
        }
    }
    ll ans = mfg.max_flow(s, t);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
