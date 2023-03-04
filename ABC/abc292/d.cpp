#include <iostream>
#include <vector>
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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> V(N, 0);

    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.unite(u, v);
        V[u]++;
        V[v]++;
    }

    vector<int> vertexes(N, 0), edges(N, 0);
    for (int v = 0; v < N; v++) {
        int r = uf.root(v);
        vertexes[r]++;
        edges[r] += V[v];
    }

    for (int v = 0; v < N; v++) {
        if (vertexes[v] != edges[v] / 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
