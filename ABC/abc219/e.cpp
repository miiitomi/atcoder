#include <bits/stdc++.h>
using namespace std;

vector<int> mawari = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};

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

bool f(int k, vector<vector<int>> &A) {
    for (int i = 0; i < 16; i++) {
        if (k & (1 << i)) continue;
        if (A[i / 4][i % 4] == 1) return false;
    }
    return true;
}

bool g(int k) {
    set<int> S, T;
    for (int j = 0; j < 16; j++) {
        if (k & (1 << j)) S.insert(j);
        else T.insert(j);
    }
    UnionFind uf1(16), uf2(16);
    for (int s : S) {
        if (s%4 < 3 && S.count(s+1)) uf1.unite(s, s+1);
        if (s < 12 && S.count(s + 4)) uf1.unite(s, s+4);
    }

    for (int s : T) {
        if (s%4 < 3 && T.count(s+1)) uf2.unite(s, s+1);
        if (s < 12 && T.count(s + 4)) uf2.unite(s, s+4);
    }   

    if (uf1.size(*S.begin()) != (int)S.size()) return false;

    if (!T.empty()) {
        for (int t : T) {
            bool x = false;
            for (int y : mawari) {
                if (uf2.issame(t, y)) {
                    x = true;
                    break;
                }
            }
            if (!x) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> A(4, vector<int>(4, -1));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cin >> A[i][j];
    }

    int ans = 0;
    for (int k = 0; k < (1 << 16); k++) {
        if (f(k, A)) {
            if (g(k)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
