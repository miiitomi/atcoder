// https://atcoder.jp/contests/abc181/tasks/abc181_f
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
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    double left = 0.0, right = 100.0;
    for (int k = 0; k < 50; k++) {
        double r = (left + right) / 2.0;
        UnionFind uf(N+2);
        for (int i = 0; i < N; i++) {
            if (y[i]+100.0 <= 2*r) uf.unite(i, N);
            if (100.0-y[i] <= 2*r) uf.unite(i, N+1);
            for (int j = i+1; j < N; j++) {
                double d = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+0.0);
                if (d <= 2*r) uf.unite(i, j);
            }
        }
        if (uf.issame(N, N+1)) right = r;
        else left = r;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
