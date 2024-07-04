// https://atcoder.jp/contests/abc270/tasks/abc270_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

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

ll N, M;
vector<ll> X, Y, A, B, Z;

ll f(ll k) {
    ll V = N;
    if (k >= 1) V++;
    if (k == 3) V++;
    UnionFind uf(N+2);
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> Q;
    for (int i = 0; i < M; i++) Q.push({Z[i], {A[i], B[i]}});
    if (k == 1 || k == 3) {
        for (int u = 0; u < N; u++) Q.push({X[u], {u, N}});
    }
    if (k == 2 || k == 3) {
        for (int u = 0; u < N; u++) Q.push({Y[u], {u, N+1}});
    }

    ll cost = 0;
    while (!Q.empty()) {
        auto e = Q.top();
        Q.pop();
        ll c = e.first;
        int u = e.second.first, v = e.second.second;
        if (uf.issame(u, v)) continue;
        cost += c;
        uf.unite(u, v);
    }
    if (uf.size(0) != V) return INF;
    else return cost;
}

void solve() {
    cin >> N >> M;
    X.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i];
    Y.resize(N);
    for (int i = 0; i < N; i++) cin >> Y[i];
    A.resize(M);
    B.resize(M);
    Z.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> Z[i];
        A[i]--; B[i]--;
    }
    ll ans = INF;
    for (ll k = 0; k <= 3; k++) ans = min(ans, f(k));

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
