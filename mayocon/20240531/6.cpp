// https://atcoder.jp/contests/abc219/tasks/abc219_e
#include <bits/stdc++.h>
using namespace std;

bool is_in(int x, int y) {return 0 <= x && x <= 3 && 0 <= y && y <= 3;};
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};

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
    vector<vector<int>> A(4, vector<int>(4, 0));
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cin >> A[i][j];

    int ans = 0;

    for (int s = 0; s < (1 << 16); s++) {
        bool is_ok = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int k = i*4+j;
                if (A[i][j] && (!(s & (1 << k)))) {
                    is_ok = false;
                }
            }
        }

        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         if ((A[i][j] == A[i+1][j+1]) && (A[i][j+1] == A[i+1][j]) && (A[i][j] != A[i][j+1])) {
        //             is_ok = false;
        //         }
        //     }
        // }

        UnionFind uf(17);
        int tmp = 1, kk = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int k = 4*i + j;
                if (s & (1 << k)) {
                    kk = k;
                    for (int l = 0; l < 4; l++) {
                        int x = i+dx[l], y = j + dy[l];
                        if (!is_in(x, y)) continue;
                        int z = 4*x + y;
                        if (s & (1 << z)) uf.unite(k, z);
                    }
                } else {
                    tmp++;
                    for (int l = 0; l < 4; l++) {
                        int x = i+dx[l], y = j + dy[l];
                        if (!is_in(x, y)) {
                            uf.unite(k, 16);
                        } else {
                            int z = 4*x + y;
                            if (!(s & (1 << z))) uf.unite(k, z);
                        }
                    }
                }
            }
        }

        if (tmp != uf.size(16)) is_ok = false;
        if (uf.size(kk) != 17-tmp) is_ok = false;

        if (is_ok) ans++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
