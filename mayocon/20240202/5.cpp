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
    vector<map<int,int>> mp(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        mp[i][c] = 1;
    }
    UnionFind uf(N);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (uf.issame(a, b)) continue;
            a = uf.root(a);
            b = uf.root(b);
            uf.unite(a, b);
            int c = uf.root(a);
            if (a == c) swap(a, b);

            for (auto iter = mp[a].begin(); iter != mp[a].end(); iter++) {
                mp[c][iter->first] += iter->second;
            }

        } else {
            int x, c;
            cin >> x >> c;
            x--;
            x = uf.root(x);
            cout << mp[x][c] << "\n";
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
