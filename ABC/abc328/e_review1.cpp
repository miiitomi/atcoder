#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll N, M, K;
vector<int> U, V;
vector<ll> W;
ll ans;

void dfs(vector<int> &v) {
    UnionFind uf(N);
    ll tmp = 0;
    bool ok = true;
    for (int i = 0; i < M; i++) {
        if (v[i] == 0) continue;
        if (!uf.issame(U[i], V[i])) {
            uf.unite(U[i], V[i]);
            tmp += W[i];
        } else {
            ok = false;
            break;
        }
    }

    if (ok) ans = min(ans, tmp % K);

    bool nxt = false;
    int cnt = 0;
    for (int i = M-1; i >= 0; i--) {
        if (v[i] == 1) {
            cnt++;
            if (i < M-1 && v[i+1] == 0) {
                v[i] = 0;
                for (int j = 1; j <= cnt; j++) v[i + j] = 1;
                for (int j = cnt + 1; j + i < M; j++) v[i + j] = 0;
                nxt = true;
            }
        }
        if (nxt) break;
    }

    if (nxt) dfs(v);
}

int main() {
    cin >> N >> M >> K;
    U.resize(M);
    V.resize(M);
    W.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--;
        V[i]--;
    }
    ans = K;

    vector<int> v(M, 0);
    for (int i = 0; i < N-1; i++) v[i] = 1;
    dfs(v);

    cout << ans << endl;
}
