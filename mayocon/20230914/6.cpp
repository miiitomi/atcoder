// https://atcoder.jp/contests/abc219/tasks/abc219_e
#include <bits/stdc++.h>
using namespace std;

int start;
vector<int> A(16, 0);
vector<vector<int>> G(16);

vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};

bool isin(int x, int y) {
    return (0 <= x && x < 4 && 0 <= y && y < 4);
}

void dfs(int s, int v, vector<bool> &reached) {
    for (int w : G[v]) {
        if ((s & (1 << w)) && !reached[w]) {
            reached[w] = true;
            dfs(s, w, reached);
        }
    }
}

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



bool f(int s) {
    vector<bool> reached(16, false);
    reached[start] = true;
    dfs(s, start, reached);

    vector<int> done(16, -1);

    for (int k = 0; k < 16; k++) {
        if (s & (1 << k)) {
            if (!reached[k]) return false;
        }
    }

    UnionFind uf(17);
    int c = 1;
    for (int v = 0; v < 16; v++) {
        if (s & (1 << v)) continue;
        c++;
        int x = v / 4, y = v % 4;
        for (int k = 0; k < 4; k++) {
            if (!isin(x+dx[k], y+dy[k])) uf.unite(v, 16);
            else {
                int w = 4*(x+dx[k])+y+dy[k];
                if (!(s & (1 << w))) uf.unite(v, w);
            }
        }
    }

    return (uf.size(16) == c);
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i*4 + j];
            if (A[i*4 + j] == 1) start = i*4 + j;
        }
    }

    for (int i = 0; i < 16; i++) {
        int x = i / 4, y = i % 4;
        for (int k = 0; k < 4; k++) {
            if (isin(x + dx[k], y + dy[k])) G[i].push_back(4*(x+dx[k]) + (y+dy[k]));
        }
    }

    int ans = 0;
    for (int s = 0; s < (1 << 16); s++) {
        bool ok = true;
        for (int k = 0; k < 16; k++) {
            if ((A[k] == 1) && !(s & (1 << k))) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        ans += f(s);
    }

    cout << ans << endl;
}
