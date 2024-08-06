// https://atcoder.jp/contests/abc304/tasks/abc304_c
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

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void solve() {
    ll N, D;
    cin >> N >> D;
    D = D*D;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (dist(X[i], Y[i], X[j], Y[j]) <= D) {
                uf.unite(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (uf.issame(i, 0)) cout << "Yes\n";
        else cout << "No\n";
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
