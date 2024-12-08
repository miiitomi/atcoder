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

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll, pair<int,int>>> V(M);
    for (int i = 0; i < M; i++) {
        cin >> V[i].second.first >> V[i].second.second >> V[i].first;
        V[i].second.first--;
        V[i].second.second--;
    }
    sort(V.begin(), V.end());
    vector<ll> A(N, 0), B(N, 0);
    for (int i = 1; i <= 2*K; i++) {
        ll a;
        cin >> a;
        if (i <= K) A[a-1]++;
        else B[a-1]++;
    }

    ll ans = 0;
    UnionFind uf(N);
    for (auto &p : V) {
        ll w = p.first;
        auto [u, v] = p.second;
        if (uf.issame(u, v)) continue;
        u = uf.root(u);
        v = uf.root(v);
        uf.unite(u, v);
        ll r = uf.root(u);
        ll au = A[u], bu = B[u], av = A[v], bv = B[v];
        A[u] -= au;
        B[u] -= bu;
        A[v] -= av;
        B[v] -= bv;
        A[r] += au + av;
        B[r] += bu + bv;
        ll x = min(A[r], B[r]);
        ans += w * x;
        A[r] -= x;
        B[r] -= x;
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
