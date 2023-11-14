// https://atcoder.jp/contests/abc328/tasks/abc328_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;
vector<int> u, v;
vector<ll> w;
ll ans;

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

void f(vector<int> &V) {
    UnionFind uf(N);
    ll tmp = 0;
    for (int i = 0; i < M; i++) {
        if (V[i] == 0) continue;
        if (uf.issame(u[i], v[i])) return;
        tmp += w[i];
        uf.unite(u[i], v[i]);
    }
    ans = min(ans, tmp % K);
}

int main() {
    cin >> N >> M >> K;
    u.resize(M);
    v.resize(M);
    w.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }

    ans = K;
    vector<int> V(M, 0);
    for (int i = 0; i < N-1; i++) V[M-1-i] = 1;
    do {
        f(V);
    } while (next_permutation(V.begin(), V.end()));

    cout << ans << endl;
}
