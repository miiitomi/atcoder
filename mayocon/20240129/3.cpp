// https://atcoder.jp/contests/abc292/tasks/abc292_d
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

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    UnionFind uf(N);
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        uf.unite(u, v);
    }

    vector<vector<int>> V(N);
    for (int u = 0; u < N; u++) {
        V[uf.root(u)].push_back(u);
    }
    vector<int> cnt(N, 0);
    for (int u = 0; u < N; u++) {
        for (int v : V[u]) cnt[u] += G[v].size();
        if (cnt[u]/2 != V[u].size()) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
