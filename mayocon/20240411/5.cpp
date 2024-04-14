// https://atcoder.jp/contests/abc183/tasks/abc183_f
#include <bits/stdc++.h>
using namespace std;

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
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    vector<map<int,int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
        V[i][C[i]] = 1;
    }
    UnionFind uf(N);
    while (Q--) {
        int k, a, b;
        cin >> k >> a >> b;
        a--;
        b--;
        if (k == 1) {
            int s = uf.root(a), t = uf.root(b);
            if (uf.unite(a, b)) {
                if (t != uf.root(b)) swap(s, t);
                for (auto iter = V[s].begin(); iter != V[s].end(); iter++) {
                    V[t][iter->first] += iter->second;
                }
            }
        } else {
            cout << V[uf.root(a)][b] << "\n";
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
