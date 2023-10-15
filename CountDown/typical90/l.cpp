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

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

bool is_in(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int to_int(int x, int y) {
    return x*W + y;
}

int main() {
    cin >> H >> W;

    vector<bool> is_red(H*W, false);
    UnionFind uf(H*W);

    int Q;
    cin >> Q;
    
    for (int t = 0; t < Q; t++) {
        int q;
        cin >> q;

        if (q == 1) {
            int r, c;
            cin >> r >> c;
            r--;
            c--;

            is_red[to_int(r, c)] = true;
            for (int k = 0; k < 4; k++) {
                int x = r + dx[k], y = c + dy[k];
                if (!is_in(x, y) || !is_red[to_int(x, y)]) continue;
                uf.unite(to_int(r, c), to_int(x, y));
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            if (is_red[to_int(ra, ca)] && uf.issame(to_int(ra, ca), to_int(rb, cb))) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
