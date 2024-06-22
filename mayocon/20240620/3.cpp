// https://atcoder.jp/contests/abc350/tasks/abc350_d
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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.unite(a, b);
    }

    vector<ll> cnt(N, 0), num_relation(N, 0);
    for (int i = 0; i < N; i++) {
        int r = uf.root(i);
        cnt[r]++;
        num_relation[r] += (int)G[i].size();
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 0) continue;
        ll tmp = cnt[i] * (cnt[i]-1) / 2;
        tmp -= num_relation[i]/2;
        ans += tmp;
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
