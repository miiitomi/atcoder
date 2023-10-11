// https://atcoder.jp/contests/abc235/tasks/abc235_e
#include <bits/stdc++.h>
using namespace std;

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

struct Edge {
    int u;
    int v;
    int w;
    bool is_query;
    int id;

    Edge(int _u, int _v, int _w, bool _is_query, int _i) {
        u = _u;
        v = _v;
        w = _w;
        is_query = _is_query;
        id = _i;
    }
};

bool cmp(Edge &x, Edge &y) {
    return x.w < y.w;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<Edge> E;
    E.reserve(M+Q);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E.push_back(Edge(a, b, c, false, -1));
    }
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E.push_back(Edge(a, b, c, true, i));
    }

    sort(E.begin(), E.end(), cmp);
    vector<bool> is_in(Q, true);

    UnionFind uf(N);
    for (auto e : E) {
        if (e.is_query && uf.issame(e.u, e.v)) is_in[e.id] = false;
        else if (!e.is_query && !uf.issame(e.u, e.v)) uf.unite(e.u, e.v);
    }

    for (int i = 0; i < Q; i++) {
        if (is_in[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
