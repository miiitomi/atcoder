#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int from, to;
    ll weight;
    Edge(int f, int t, ll w): from(f), to(t), weight(w) {}
};

bool cmp(Edge &e1, Edge &e2) {
    return e1.weight < e2.weight;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<Edge> V;
    V.reserve(M);
    for (int i = 0; i < M; i++) {
        ll c;
        int l, r;
        cin >> c >> l >> r;
        l--;
        V.push_back(Edge(l, r, c));
    }

    sort(V.begin(), V.end(), cmp);
    ll ans = 0;
    UnionFind uf(N+1);
    for (Edge &e : V) {
        if (!uf.issame(e.from, e.to)) {
            ans += e.weight;
            uf.unite(e.from, e.to);
        }
    }

    if (uf.size(0) != N+1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
