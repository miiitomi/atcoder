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
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind uf1(N), uf2(N);
    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        uf1.unite(p, q);
    }
    for (int i = 0; i < L; i++) {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        uf2.unite(r, s);
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        pair<int, int> p;
        p.first = uf1.root(i);
        p.second = uf2.root(i);
        mp[p]++;
    }

    for (int i = 0; i < N; i++) {
        pair<int, int> p;
        p.first = uf1.root(i);
        p.second = uf2.root(i);
        cout << mp[p];
        if (i != N-1) cout << " ";
        else cout << endl;
    }
}
