#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> dp;


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

void dfs1(int v, vector<vector<int>> &G, vector<int> &I, vector<bool> &used) {
    if (used[v]) return;
    used[v] = true;

    for (int w : G[v]) {
        dfs1(w, G, I, used);
    }
    I.push_back(v);
}

void dfs2(int v, vector<vector<int>> &H, vector<int> &J, int &i) {
    if (J[v] != -1) return;
    J[v] = i;
    for (int w : H[v]) {
        dfs2(w, H, J, i);
    }
}

ll f(int u, UnionFind &uf, vector<int> &a) {
    if (dp[u] != -1) return dp[u];
    if (u != uf.root(u)) return dp[u] = f(uf.root(u), uf, a);
    dp[u] = uf.size(u);
    if (!uf.issame(u, a[u])) dp[u] += f(a[u], uf, a);
    return dp[u];
}

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<vector<int>> G(N), H(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        G[i].push_back(a[i]);
        H[a[i]].push_back(i);
    }

    vector<int> I;
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++) {
        dfs1(i, G, I, used);
    }

    vector<int> J(N, -1);
    for (int i = 0; i < N; i++) {
        int v = I[N - 1 - i];
        dfs2(v, H, J, i);
    }

    map<int,int> mp;
    for (int i = 0; i < N; i++) mp[J[i]] = i;

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        uf.unite(i, mp[J[i]]);
    }

    dp.assign(N, -1);
    ll ans = 0;
    for (int u = 0; u < N; u++) {
        ans += f(u, uf, a);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
