// https://atcoder.jp/contests/abc120/tasks/abc120_d
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

void solve() {
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<pair<int,int>> V(M);
    for (int i = 0; i < M; i++) {
        cin >> V[i].first >> V[i].second;
        V[i].first--;
        V[i].second--;
    }
    vector<ll> ans;
    ll tmp = N*(N-1)/2;
    while (!V.empty()) {
        ans.push_back(tmp);
        int u = V.back().first, v = V.back().second;
        V.pop_back();
        if (uf.issame(u, v)) continue;
        ll s = uf.size(u), t = uf.size(v);
        tmp -= s*t;
        uf.unite(u, v);
    }

    while (!ans.empty()) {
        cout << ans.back() << "\n";
        ans.pop_back();
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
