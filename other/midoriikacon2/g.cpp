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
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }
    vector<vector<int>> V(N);
    for (int i = 0; i < N; i++) V[C[i]].push_back(i);

    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (C[u] != C[v]) continue;
        uf.unite(u, v);
    }

    int ans = 0;
    set<int> S;
    for (int i = 0; i < N; i++) {
        if (V[i].size() <= 1) continue;
        for (int j : V[i]) {
            S.insert(uf.root(j));
        }
        ans += S.size()-1;
        S = {};
    }
    cout << ans << endl;
}
