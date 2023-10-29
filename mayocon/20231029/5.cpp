// https://atcoder.jp/contests/abc126/tasks/abc126_e
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

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        uf.unite(u, v);
    }

    unordered_set<int> S;
    for (int i = 0; i < N; i++) S.insert(uf.root(i));

    cout << (int)S.size() << endl;
}
