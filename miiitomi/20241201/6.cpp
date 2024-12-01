// https://atcoder.jp/contests/abc337/tasks/abc337_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct Fenwick {
    int n;
    vector<T> data;

    Fenwick(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, T x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    T _sum(int i) {
        // compute sum of a[k] for k in [0, i)
        T ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    T query(int a, int b) {
        // compute sum of a[k] for k in [a, b)
        return _sum(b) - _sum(a);
    }
};

int N;
vector<vector<int>> G;
vector<ll> imos, in, path;
Fenwick<ll> ft(0);

void dfs(int u, int p) {
    in[u] = path.size();
    path.push_back(u);
    ll tmp_u = ft.query(0, u), tmp_p = ft.query(0, p);
    ft.add(u, 1);
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tmp_u = u - (ft.query(0, u) - tmp_u);
    tmp_p = ft.query(0, p) - tmp_p;
    imos[0] += tmp_p;
    imos[in[u]] += tmp_u - tmp_p;
    imos[path.size()] += -tmp_u + tmp_p;
    imos[N] -= tmp_p;
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    imos.assign(N+1, 0);
    in.assign(N, -1);
    ft = Fenwick<ll>(N);
    dfs(0, 0);
    for (int i = 0; i < N; i++) imos[i+1] += imos[i];
    for (int i = 0; i < N; i++) {
        cout << imos[in[i]];
        if (i == N-1) cout << "\n";
        else cout << " ";
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
