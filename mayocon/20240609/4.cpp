// https://atcoder.jp/contests/abc352/tasks/abc352_e
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
    vector<ll> K(M), C(M), v;
    vector<vector<ll>> A(M);
    for (int i = 0; i < M; i++) {
        v.push_back(i);
        cin >> K[i] >> C[i];
        A[i].resize(K[i]);
        for (int j = 0; j < K[i]; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    sort(v.begin(), v.end(), [&](const int &l, const int &r) {return C[l] < C[r];});
    UnionFind uf(N);
    ll ans = 0;
    for (int i : v) {
        int u = A[i][0];
        for (int v : A[i]) {
            if (uf.issame(u, v)) continue;
            ans += C[i];
            uf.unite(u, v);
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
