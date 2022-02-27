// https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A

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
    int N, M;
    cin >> N >> M;

    vector<pair<int, pair<int, int>>> V;
    for (int i = 0; i < M; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        V.push_back(make_pair(w, make_pair(s, t)));
    }

    sort(V.begin(), V.end());
    int ans = 0;
    UnionFind uf(N);

    for (auto p : V) {
        int w = p.first;
        int s = p.second.first;
        int t = p.second.second;
        if (!uf.issame(s, t)) {
            ans += w;
            uf.unite(s, t);
        }
    }

    cout << ans << endl;
}
