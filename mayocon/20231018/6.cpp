// https://atcoder.jp/contests/abc314/tasks/abc314_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

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
    int N;
    cin >> N;

    vector<int> par(N, -1);
    vector<vector<int>> child(N);
    vector<mint> ex(N, 0);
    vector<int> f(N);
    for (int i = 0; i < N; i++) f[i] = i;

    par.reserve(2*N);
    child.reserve(2*N);
    ex.reserve(2*N);

    UnionFind uf(N);

    for (int i = 0; i < N-1; i++) {
        int v, w;
        cin >> v >> w;
        v--;
        w--;
        mint a = (mint)uf.size(v), b = (mint)uf.size(w);
        uf.unite(v, w);

        int m = (int)par.size();
        int p = f[v], q = f[w];
        while (par[p] != -1) {
            int p_new = par[p];
            par[p] = m;
            p = p_new;
        }
        while (par[q] != -1) {
            int q_new = par[q];
            par[q] = m;
            q = q_new;
        }
        f[v] = m;
        f[w] = m;

        par.push_back(-1);
        par[p] = m;
        par[q] = m;
        child.push_back({p,q});
        mint x = (a + b).inv();
        ex[p] = a * x;
        ex[q] = b * x;
        ex.push_back(0);
    }

    for (int i = (int)par.size()-2; i >= N; i--) {
        for (int c : child[i]) {
            ex[c] += ex[i];
        }
    }

    for (int i = 0; i < N; i++) cout << ex[i].val() << " ";
    cout << endl;
}
