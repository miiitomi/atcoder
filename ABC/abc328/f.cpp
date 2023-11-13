#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    ll N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<ll> X(N, 0);
    vector<ll> S;
    vector<vector<int>> C(N);
    for (int i = 0; i < N; i++) C[i].push_back(i);

    for (int q = 0; q < Q; q++) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--;
        b--;
        if (uf.issame(a, b)) {
            if (X[a] - X[b] == d) S.push_back(q); 
        } else {
            if (uf.size(a) < uf.size(b)) {
                swap(a, b);
                d = -d;
            }
            int u = uf.root(a), v = uf.root(b);
            ll r = X[a] - X[b] - d;
            while (!C[v].empty()) {
                ll s = C[v].back();
                C[v].pop_back();
                X[s] += r;
                C[u].push_back(s);
            }
            uf.unite(a, b);
            S.push_back(q);
        }
    }

    for (int q : S) cout << q + 1 << " ";
    cout << endl;
}
