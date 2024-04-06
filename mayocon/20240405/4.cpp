// https://atcoder.jp/contests/abc259/tasks/abc259_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

ll d2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    ll N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(N), y(N), r(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> r[i];

    UnionFind uf(N);
    vector<int> S, T;

    for (int i = 0; i < N; i++) {
        if (d2(x[i], y[i], sx, sy) == r[i]*r[i]) S.push_back(i);
        if (d2(x[i], y[i], tx, ty) == r[i]*r[i]) T.push_back(i);

        for (int j = 0; j < N; j++) {
            if (uf.issame(i, j)) continue;
            if ((r[i]-r[j])*(r[i]-r[j]) <= d2(x[i], y[i], x[j], y[j]) && d2(x[i], y[i], x[j], y[j]) <= (r[i]+r[j])*(r[i]+r[j])) {
                uf.unite(i, j);
            }
        }
    }
    for (int i : S) {
        for (int j : T) {
            if (i == j || uf.issame(i, j)) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
