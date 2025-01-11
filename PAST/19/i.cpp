// https://atcoder.jp/contests/past19-open/tasks/past19_i
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

struct Edge {
    ll a, b, d;
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<Edge> E(M);
    for (int i = 0; i < M; i++) {
        cin >> E[i].a >> E[i].b >> E[i].d;
        E[i].a--; E[i].b--;
    }
    sort(E.begin(), E.end(), [](const Edge &l, const Edge &r) {return l.d < r.d;});
    UnionFind uf(N);
    while (!E.empty()) {
        ll D = E.back().d;
        while (!E.empty() && E.back().d == D) {
            uf.unite(E.back().a, E.back().b);
            E.pop_back();
        }

        if (uf.size(0) == N) {
            cout << D << "\n";
            return;
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
