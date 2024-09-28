#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
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

template<typename T> struct DisjointSparseTable {
    T identity_element = {(int)1e+9, (int)1e+9};    // TODO: Change identity_element if needed. e.g.) 0, 1, INF, etc.
    T f(T l, T r) {return min(l, r);}    // TODO: Change the function f if needed. e.g) min, max, etc.
    vector<vector<T>> st;
    vector<int> lookup;

    DisjointSparseTable(const vector<T> &v) {
        int b = 0;
        while ((1 << b) <= (int)v.size()) ++b;
        st.resize(b, vector<T>(v.size(), identity_element));
        for (int i = 0; i < (int)v.size(); i++) st[0][i] = v[i];
        for (int i = 1; i < b; i++) {
        int shift = 1 << i;
        for (int j = 0; j < (int)v.size(); j += (shift << 1)) {
                int t = min(j + shift, (int)v.size());
                st[i][t - 1] = v[t - 1];
                for (int k = t - 2; k >= j; k--) st[i][k] = f(v[k], st[i][k + 1]);
                if ((int)v.size() <= t) break;
                st[i][t] = v[t];
                int r = min(t + shift, (int)v.size());
                for (int k = t + 1; k < r; k++) st[i][k] = f(st[i][k - 1], v[k]);
            }
        }
        lookup.resize(1 << b);
        for (int i = 2; i < (int)lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    T query(int l, int r) {
        // Return the answer in the interval [l, r).
        if (l >= --r) return st[0][l];
        int p = lookup[l ^ r];
        return f(st[p][l], st[p][r]);
    }
};

void dfs(int u, int p, int d, vector<vector<int>> &G, vector<int> &in, vector<int> &out, vector<pair<ll,ll>> &depth) {
    in[u] = depth.size();
    depth.push_back({d, u});
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, d+1, G, in, out, depth);
        depth.push_back({d, u});
    }
    out[u] = depth.size();
    depth.push_back({d, u});
}

vector<int> retun_path(int s, int t, vector<vector<int>> &G) {
    int N = G.size();
    vector<int> d(N, -1), pre(N, -1);
    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v : G[u]) {
            if (d[v] != -1) continue;
            d[v] = d[u]+1;
            pre[v] = u;
            Q.push(v);
        }
    }
    int u = t;
    vector<int> path;
    while (u != s) {
        path.push_back(u);
        u = pre[u];
    }
    path.push_back(u);
    return path;
}

void solve() {
    ll N, p=-1, q=-1;
    cin >> N;
    UnionFind uf(N);
    vector<vector<int>> G(N);
    vector<int> U(N), V(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        U[i] = u; V[i] = v;
        if (uf.issame(u, v)) {
            p = u; q = v;
            continue;
        }
        uf.unite(u, v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> in(N), out(N);
    vector<pair<ll, ll>> depth;
    dfs(0, -1, 0, G, in, out, depth);
    DisjointSparseTable<pair<ll,ll>> dsu(depth);
    vector<int> path = retun_path(p, q, G);
    int r = *min_element(path.begin(), path.end());
    set<int> st;
    for (int i : path) st.insert(i);
    vector<vector<int>> H(N);
    for (int i = 0; i < N; i++) {
        int u = U[i], v = V[i];
        if (st.contains(u) && st.contains(v)) continue;
        if (st.contains(u)) u = r;
        else if (st.contains(v)) v = r;
        H[u].push_back(v);
        H[v].push_back(u);
    }
    vector<int> in1(N), out1(N);
    vector<pair<ll,ll>> depth1;
    dfs(0, -1, 0, H, in1, out1, depth1);
    DisjointSparseTable<pair<ll,ll>> dsu1(depth1);

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int lca = dsu.query(min(in[a],in[b]), max(out[a], out[b])).second;
        int dist = depth[in[a]].first + depth[in[b]].first - 2*depth[in[lca]].first;
        if (st.contains(a) && st.contains(b)) {
            cout << max(dist, (int)path.size() - dist) << "\n";
            continue;
        }
        if (st.contains(b)) swap(a, b);
        if (st.contains(a)) {
            int lca1 = dsu1.query(min(in1[r], in1[b]), max(out1[r], out1[b])).second;
            int dist1 = depth1[in1[r]].first + depth1[in1[b]].first - 2 * depth1[in1[lca1]].first;
            if (dist == dist1) {
                cout << -1 << "\n";
                continue;
            }
            cout << max(dist, dist1 + (int)path.size() - (dist-dist1)) << "\n";
            continue;
        }
        int lca2 = dsu1.query(min(in1[a], in1[b]), max(out1[a], out1[b])).second;
        int dist2 = depth1[in1[a]].first + depth1[in1[b]].first - 2 * depth1[in1[lca2]].first;
        if (dist == dist2) {
            cout << -1 << "\n";
            continue;
        }
        cout << max(dist, dist2 + (int)path.size() - (dist - dist2)) << "\n";
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
