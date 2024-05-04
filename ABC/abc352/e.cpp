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
    int N, M;
    cin >> N >> M;
    vector<int> K(M), C(M), v(M);
    vector<vector<int>> A(M);
    for (int i = 0; i < M; i++) {
        cin >> K[i] >> C[i];
        A[i].resize(K[i]);
        for (int j = 0; j < K[i]; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
        v[i] = i;
    }
    sort(v.begin(), v.end(), [&](const int &l, const int &r) {return C[l] < C[r];});
    ll ans = 0;
    UnionFind uf(N);
    for (int i : v) {
        int u = A[i][0];
        for (int j = 1; j < K[i]; j++) {
            if (!uf.issame(u, A[i][j])) {
                ans += C[i];
                uf.unite(u, A[i][j]);
            }
        }
    }

    if (uf.size(0) == N) cout << ans << "\n";
    else cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
