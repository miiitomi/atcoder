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
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.unite(u, v);
    }

    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int par = uf.root(i);
        mp[par]++;
    }

    int sum = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        sum += iter->second - 1;
    }

    cout << M - sum << endl;
}
