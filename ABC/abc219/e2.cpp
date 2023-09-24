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

bool is_in(int x, int y) {
    return 0 <= x && x < 4 && 0 <= y && y < 4;
}

int to_idx(int x, int y) {
    return 4*x + y;
}

vector<int> dx{0, 0, -1, 1}, dy{1, -1, 0, 0};

int main() {
    vector<int> A(16);
    int t = -1;
    for (int i = 0; i < 16; i++) {
        cin >> A[i];
        if (A[i] == 1) t = i;
    }
    int ans = 0;

    for (int s = 1; s < (1 << 16); s++) {
        bool all_in = true;
        int num_in = 0;
        for (int i = 0; i < 16; i++) {
            if (s & (1 << i)) num_in++;
            if (A[i] == 1 && !(s & (1 << i))) all_in = false;
        }

        if (!all_in) continue;

        UnionFind uf(17);
        
        for (int i = 0; i < 16; i++) {
            int x = i / 4, y = i % 4;

            if (s & (1 << i)) {
                for (int k = 0; k < 4; k++) {
                    int a = x + dx[k], b = y + dy[k];
                    int j = to_idx(a, b);
                    if (!is_in(a, b) || !(s & (1 << j))) continue;
                    uf.unite(i, j);
                }
            } else {
                for (int k = 0; k < 4; k++) {
                    int a = x + dx[k], b = y + dy[k];
                    int j = to_idx(a, b);
                    if (!is_in(a, b)) {
                        uf.unite(i, 16);
                    } else if (!(s & (1 << j))) {
                        uf.unite(i, j);
                    }
                }                
            }
        }

        if (uf.size(t) == num_in && uf.size(16) == 17 - num_in) ans++;
    }

    cout << ans << endl;
}
