#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 2e+9;
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

vector<pair<int,int>> d{{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

void solve() {
    ll N, T;
    cin >> N >> T;
    vector<pair<ll,ll>> A(N), B(N);
    map<pair<ll,ll>, ll> mp;
    for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    for (int i = 0; i < N; i++) {
        cin >> B[i].first >> B[i].second;
        mp[B[i]] = i;
    }
    int s = 2*N, t = 2*N+1;
    MaxFlowGraph<int> G(2*N + 2);
    for (int i = 0; i < N; i++) {
        G.add_edge(s, i, 1);
        G.add_edge(N+i, t, 1);
        for (int k = 0; k < 8; k++) {
            ll x = A[i].first + T*d[k].first;
            ll y = A[i].second + T*d[k].second;
            if (mp.contains(make_pair(x,y))) {
                G.add_edge(i, N+mp[{x,y}], 1);
            }
        }
    }
    ll ans = G.max_flow(s, t);
    if (ans != N) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < N; i++) {
        for (auto e : G.G[i]) {
            if (e.to != s && e.cap == 0) {
                auto p = B[e.to-N];
                for (int k = 0; k < 8; k++) {
                    if (A[i].first+T*d[k].first == p.first && A[i].second+T*d[k].second == p.second) {
                        cout << k+1 << " ";
                        continue;
                    }
                }
                continue;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
