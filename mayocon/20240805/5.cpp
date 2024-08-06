// https://atcoder.jp/contests/abc120/tasks/abc120_d
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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    vector<ll> ans(M+1, N*(N-1)/2);
    UnionFind uf(N);
    for (int i = M-1; i >= 0; i--) {
        ll a = A[i], b = B[i];
        if (uf.issame(a, b)) {
            ans[i] = ans[i+1];
        } else {
            ll s = uf.size(A[i]), t = uf.size(B[i]);
            ans[i] = ans[i+1] - s*t;
            uf.unite(a, b);
        }
    }
    for (int i = 1; i <= M; i++) {
        cout << ans[i] << "\n";
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
