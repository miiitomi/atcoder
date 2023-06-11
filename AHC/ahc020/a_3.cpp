#include <bits/stdc++.h>
using namespace std;

int N, M, K;

struct Edge {
    int id, to, weight;
    Edge(int id, int to, int weight) : id(id), to(to), weight(weight) {}
};

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};


int hankei(int x, int y, int a, int b) {
    double d = (x-a)*(x-a) + (y-b)*(y-b);
    double q = sqrt(d);
    int r = (int)q;
    if (q - r > (double)0.0) r++;
    return r;
}

void nearest(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, vector<int> &P) {
    for (int i = 0; i < K; i++) {
        int min_h = 1e+5;
        int min_idx = -1;
        for (int j = 0; j < N; j++) {
            int h = hankei(x[j], y[j], a[i], b[i]);
            if (min_h > h) {
                min_h = h;
                min_idx = j;
            }
        }
        P[min_idx] = max(P[min_idx], min_h);
    }
}

void dijkstra(vector<vector<Edge>> &G, vector<int> &B) {
    vector<int> d(N, 1e+8);
    d[0] = 0;
    vector<int> last_used_edge(N, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int dist = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d[v] < dist) continue;

        if (v != 0) B[last_used_edge[v]] = 1;

        for (auto e : G[v]) {
            if (d[e.to] > d[v] + e.weight) {
                d[e.to] = d[v] + e.weight;
                pq.push(make_pair(d[e.to], e.to));
                last_used_edge[e.to] = e.id;
            }
        }
    }
}

void remove_edge(vector<vector<Edge>> &G, vector<int> &P, vector<int> &B, vector<pair<int, int>> &edges, vector<int> &u, vector<int> &v) {
    for (auto p : edges) {
        int id = p.second;
        if (B[id] == 0) continue;

        UnionFind uf(N);
        for (int i = 0; i < M; i++) {
            if (i == id || B[i] == 0) continue;
            uf.unite(u[i], v[i]);
        }

        bool can_remove = true;
        for (int x = 1; x < N; x++) {
            if (P[x] > 0 && !uf.issame(0, x)) {
                can_remove = false;
                break;
            }
        }

        if (can_remove) B[id] = 0;
    }
}

int main() {
    cin >> N >> M >> K;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<Edge>> G(N);
    vector<pair<int, int>> edges(M);
    vector<int> u(M), v(M), w(M);
    for (int i = 0; i < M; i++) {
        int u_, v_, w_;
        cin >> u_ >> v_ >> w_;
        u_--;
        v_--;
        G[u_].push_back(Edge(i, v_, w_));
        G[v_].push_back(Edge(i, u_, w_));
        edges[i] = make_pair(w_, i);
        u[i] = u_;
        v[i] = v_;
        w[i] = w_;
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    vector<int> a(K), b(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> P(N, 0);
    vector<int> B(M, 0);

    nearest(x, y, a, b, P);
    dijkstra(G, B);

    remove_edge(G, P, B, edges, u, v);

    for (int i = 0; i < N; i++) {
        if (i != N-1) cout << P[i] << " ";
        else cout << P[i] << endl;
    }

    for (int i = 0; i < M; i++) {
        if (i != M-1) cout << B[i] << " ";
        else cout << B[i] << endl;
    }
}
