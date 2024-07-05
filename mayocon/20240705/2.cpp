// https://atcoder.jp/contests/abc289/tasks/abc289_b
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
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        a--;
        uf.unite(a, a+1);
    }
    vector<vector<int>> V(N);
    for (int i = 0; i < N; i++) {
        V[uf.root(i)].push_back(i);
    }
    vector<bool> done(N, false);
    for (int i = 0; i < N; i++) {
        if (done[i]) continue;
        int r = uf.root(i);
        sort(V[r].begin(), V[r].end());
        reverse(V[r].begin(), V[r].end());
        for (int x : V[r]) {
            cout << x+1 << " ";
            done[x] = true;
        }
    }
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
