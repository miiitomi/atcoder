// https://atcoder.jp/contests/abc288/tasks/abc288_c
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
    vector<ll> cnt(N, 0);
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++; cnt[b]++;
        uf.unite(a, b);
    }
    vector<ll> tmp(N, 0);
    for (int i = 0; i < N; i++) {
        tmp[uf.root(i)] += cnt[i];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i != uf.root(i)) continue;
        ans += tmp[i]/2 - (uf.size(i) - 1);
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
