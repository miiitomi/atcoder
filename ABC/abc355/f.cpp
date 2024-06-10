#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int c;
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1), c(n) {}

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
        c--;
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<UnionFind> uf(11, UnionFind(N));
    for (int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int k = c; k <= 10; k++) uf[k].unite(a-1, b-1);
    }

    while (Q--) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int k = w; k <= 10; k++) uf[k].unite(u-1, v-1);

        int ans = 0;
        for (int k = 1; k <= 10; k++) ans += k * (uf[k-1].c - uf[k].c);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
