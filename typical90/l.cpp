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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> x(H, vector<int>(W, 0));
    UnionFind uf(H*W);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int r, c;
            cin >> r >> c;
            r--;
            c--;
            x[r][c] = 1;
            if (r > 0) {
                if (x[r-1][c]) uf.unite(r*W+c, (r-1)*W+c);
            }
            if (r < H-1) {
                if (x[r+1][c]) uf.unite(r*W+c, (r+1)*W+c);
            }
            if (c > 0) {
                if (x[r][c-1]) uf.unite(r*W+c, r*W+c-1);
            }
            if (c < W-1) {
                if (x[r][c+1]) uf.unite(r*W+c, r*W+c+1);
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            if (x[ra][ca] && uf.issame(ra*W+ca, rb*W+cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
