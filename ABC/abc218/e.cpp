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
    vector<pair<int, pair<int, int>>> V(M);
    long long ans = 0LL;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[i].first = c;
        V[i].second = make_pair(a, b);
        ans += c;
    }
    sort(V.begin(), V.end());

    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        if (V[i].first <= 0) {
            uf.unite(V[i].second.first, V[i].second.second);
            ans -= V[i].first;
            continue;
        };

        if (uf.issame(V[i].second.first, V[i].second.second)) continue;

        ans -= V[i].first;
        uf.unite(V[i].second.first, V[i].second.second);
    }

    cout << ans << endl;
}
