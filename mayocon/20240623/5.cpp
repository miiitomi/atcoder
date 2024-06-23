// https://atcoder.jp/contests/abc214/tasks/abc214_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    ll N;
    cin >> N;
    UnionFind uf(N);
    ll ans = 0;
    vector<vector<ll>> G(N-1, vector<ll>(3));
    for (int i = 0; i < N-1; i++) {
        cin >> G[i][1] >> G[i][2] >> G[i][0];
        G[i][1]--;
        G[i][2]--;
    }
    sort(G.begin(), G.end());
    for (vector<ll> &V : G) {
        ll u = V[1], v = V[2], w = V[0];
        ans += w * uf.size(u) * uf.size(v);
        uf.unite(u, v);
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
