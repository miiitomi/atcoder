// https://atcoder.jp/contests/abc328/tasks/abc328_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct WeightedUnionFind {
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

int main() {
    ll N, M;
    cin >> N >> M;
    WeightedUnionFind<ll> wuf(N);
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        wuf.unite(v, u, w);
    }
    vector<ll> x(N, 0);
    for (int i = 0; i < N; i++) {
        int r = wuf.root(i);
        x[i] = wuf.diff(i, r);
    }
    for (ll a : x) {
        cout << a << " ";
    }
    cout << endl;
}
