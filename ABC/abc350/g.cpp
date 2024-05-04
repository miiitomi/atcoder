#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

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

void dfs(int u, int p, vector<int> &par, vector<vector<int>> &G) {
    par[u] = p;
    for (int v : G[u]) {
        if (v != p) dfs(v, u, par, G);
    }
}

void solve() {
    int N, Q, B=1000;
    cin >> N >> Q;
    vector<ll> a(Q), b(Q), c(Q), t(Q), u(Q), v(Q);
    for (int q = 0; q < Q; q++) cin >> a[q] >> b[q] >> c[q];
    ll x = 0;

    for (int k = 0; k*B < Q; k++) {
        vector<vector<int>> G(N);
        UnionFind uf(N);
        for (int i = 0; i < k*B; i++) {
            if (t[i] == 1) continue;
            uf.unite(u[i], v[i]);
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }
        for (int i = 0; i < N; i++) if (G[i].size() >= 2) sort(G[i].begin(), G[i].end());
        vector<int> par(N);
        for (int u = 0; u < N; u++) if (u == uf.root(u)) dfs(u, -1, par, G);

        vector<vector<int>> H(N);
        for (int i = k*B; i < min((k+1)*B, Q); i++) {
            t[i] = (a[i] * (1 + x) % MOD) % 2;
            u[i] = (b[i] * (1 + x) % MOD) % N;
            v[i] = (c[i] * (1 + x) % MOD) % N;
            if (t[i] == 0) {
                H[u[i]].push_back(v[i]);
                H[v[i]].push_back(u[i]);
            } else {
                if (uf.issame(u[i], v[i])) {
                    if (par[u[i]] != -1) {
                        auto iter = lower_bound(G[v[i]].begin(), G[v[i]].end(), par[u[i]]);
                        if (iter != G[v[i]].end() && *iter == par[u[i]]) {
                            x = par[u[i]] + 1;
                            cout << x << "\n";
                            continue;
                        }
                    }
                    if (par[v[i]] != -1) {
                        auto iter = lower_bound(G[u[i]].begin(), G[u[i]].end(), par[v[i]]);
                        if (iter != G[u[i]].end() && *iter == par[v[i]]) {
                            x = par[v[i]] + 1;
                            cout << x << "\n";
                            continue;
                        }
                    }
                    x = 0;
                    cout << x << "\n";
                } else {
                    sort(H[v[i]].begin(), H[v[i]].end());
                    sort(H[u[i]].begin(), H[u[i]].end());
                    x = 0;
                    for (int c : H[u[i]]) {
                        auto iter = lower_bound(H[v[i]].begin(), H[v[i]].end(), c);
                        if (iter != H[v[i]].end() && *iter == c) {
                            x = c+1;
                            cout << x << "\n";
                            break;
                        }
                        auto iter1 = lower_bound(G[v[i]].begin(), G[v[i]].end(), c);
                        if (iter1 != G[v[i]].end() && *iter1 == c) {
                            x = c+1;
                            cout << x << "\n";
                            break;
                        }
                    }
                    if (x != 0) continue;
                    for (int c : H[v[i]]) {
                        auto iter = lower_bound(H[u[i]].begin(), H[u[i]].end(), c);
                        if (iter != H[u[i]].end() && *iter == c) {
                            x = c+1;
                            cout << x << "\n";
                            break;
                        }
                        auto iter1 = lower_bound(G[u[i]].begin(), G[u[i]].end(), c);
                        if (iter1 != G[u[i]].end() && *iter1 == c) {
                            x = c+1;
                            cout << x << "\n";
                            break;
                        }
                    }
                    if (x == 0) cout << x << "\n";
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
