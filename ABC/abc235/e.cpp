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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> E(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        E[i] = {c, a, b};
    }
    sort(E.begin(), E.end());

    vector<vector<int>> F(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        F[i] = {w, u, v, i};
    }
    sort(F.begin(), F.end());

    vector<int> ans(Q, 0);

    UnionFind uf(N);

    int edges = 0;
    int i = 0;
    int j = 0;

    while (edges < N - 1 && i < M && j < Q) {
        if (E[i][0] < F[j][0]) {
            if (!uf.issame(E[i][1], E[i][2])) {
                uf.unite(E[i][1], E[i][2]);
                edges++;
            }
            i++;
        } else {
            if (!uf.issame(F[j][1], F[j][2])) {
                ans[F[j][3]] = 1;
            }
            j++;
        }
    }
    for (int i = 0; i < Q; i++) {
        if (ans[i] == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
