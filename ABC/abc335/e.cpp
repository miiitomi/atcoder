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

vector<int> A;

int main() {
    int N, M;
    cin >> N >> M;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    UnionFind uf(N);
    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i];
        U[i]--;
        V[i]--;
        if (A[U[i]] == A[V[i]]) uf.unite(U[i], V[i]);
    }

    if (uf.issame(0, N-1)) {
        cout << 1 <<  endl;
        return 0;
    } else if (A[N-1] <= A[0]) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u = uf.root(U[i]), v = uf.root(V[i]);
        if (u != v) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), [](const int &i, const int &j){return A[i] < A[j];});

    vector<int> dp(N, -1);
    dp[uf.root(0)] = 0;

    for (int u : v) {
        if (uf.root(u) != u) continue;
        for (int w : G[u]) if (A[u] > A[w] && dp[w] >= 0) dp[u] = max(dp[u], dp[w] + 1);
    }

    if (dp[uf.root(N-1)] < 0) cout << 0 << endl;
    else cout << dp[uf.root(N-1)] + 1 << endl;
}
