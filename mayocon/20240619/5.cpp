// https://atcoder.jp/contests/abc157/tasks/abc157_d
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
    int N, M, K;
    cin >> N >> M >> K;
    UnionFind uf(N);
    vector<vector<int>> G(N), B(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.unite(a, b);
    }
    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        B[c].push_back(d);
        B[d].push_back(c);
    }

    for (int i = 0; i < N; i++) {
        int ans = uf.size(i) - G[i].size() - 1;
        for (int j : B[i]) {
            if (uf.issame(i, j)) ans--;
        }
        cout << ans << " ";
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
