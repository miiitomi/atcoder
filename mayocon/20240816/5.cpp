// https://atcoder.jp/contests/abc328/tasks/abc328_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct WeightedUnionFind {
    vector<int> par, siz;
    vector<T> diff_weight;

    WeightedUnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        siz.assign(n, 1);
        diff_weight.assign(n, 0);
    }

    int root(int x) {
        if (par[x] == x) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    T weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool is_same(int y, int x) {
        return root(y) == root(x);
    }

    int size(int x) {
        return siz[root(x)];
    }

    bool unite(int y, int x, T w) {
        // Unite y and x so that weight(y) - weight(x) == w
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) {
            swap(x, y);
            w = -w;
        }
        siz[x] += siz[y];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    T diff(int y, int x) {
        // Return weight(y) - weight(x);
        return weight(y) - weight(x);
    }
};


void solve() {
    ll N, Q;
    cin >> N >> Q;
    WeightedUnionFind<ll> wuf(N);
    vector<ll> V;
    for (ll q = 1; q <= Q; q++) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        if (!wuf.is_same(u, v)) {
            wuf.unite(u, v, d);
            V.push_back(q);
        } else if (wuf.diff(u, v) == d) {
            V.push_back(q);
        }
    }
    for (ll x : V) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}