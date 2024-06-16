// https://atcoder.jp/contests/abc350/tasks/abc350_g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const ll B = 500;

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

void dfs(ll u, ll p, vector<ll> &par, vector<vector<ll>> &G) {
    par[u] = p;
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs(v, u, par, G);
    }
}

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<vector<ll>> G(N);
    vector<pair<ll,ll>> P;
    vector<unordered_set<ll>> Neighbors(N);
    UnionFind uf(N);
    vector<ll> par(N, -1);
    ll x = 0;

    for (int q = 0; q < Q; q++) {
        if (q % B == 0) {
            while (!P.empty()) {
                ll u = P.back().first, v = P.back().second;
                P.pop_back();
                uf.unite(u, v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
            par.assign(N, -1);
            for (ll u = 0; u < N; u++) if (par[u] == -1) dfs(u, -1, par, G);
        }

        ll a, b, c;
        cin >> a >> b >> c;
        ll t = ((a * (1 + x)) % MOD) % 2;
        ll u = ((b * (1 + x)) % MOD) % N;
        ll v = ((c * (1 + x)) % MOD) % N;

        if (t == 0) {
            P.push_back(make_pair(u, v));
            Neighbors[u].insert(v);
            Neighbors[v].insert(u);
        } else {
            x = -1;
            if (uf.issame(u, v)) {
                ll r = par[u];
                if (Neighbors[v].count(r)) {
                    x = r;
                } else {
                    r = par[v];
                    if (Neighbors[u].count(r)) {
                        x = r;
                    }
                }
            } else {
                for (auto &p : P) {
                    ll r = -1, w = -1;
                    if (p.first == u) {
                        r = p.second;
                        w = v;
                    } else if (p.first == v) {
                        r = p.second;
                        w = u;
                    } else if (p.second == u) {
                        r = p.first;
                        w = v;
                    } else if (p.second == v) {
                        r = p.first;
                        w = u;
                    }

                    if (r != -1 && Neighbors[w].count(r)) {
                        x = r;
                        break;
                    }
                }
            }

            x++;
            cout << x << "\n";
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
