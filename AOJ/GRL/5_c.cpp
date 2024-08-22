#include <bits/stdc++.h>
using namespace std;

int N;  // 頂点数（N <= 10**6）
vector<vector<int>> G;  // 木（隣接グラフ表現）
vector<int> depth;  // 頂点 0 を根としたときの深さ
vector<vector<int>> p;  // p[k][u] : u の 2^k コ前の祖先（k = 0,...,19）

void dfs(int u, int par, int k) {
    // depth と par[0]（一つ前の親）を木上のDFSで求める.
    depth[u] = k;
    if (par != -1) p[0][u] = par;
    else p[0][u] = u;
    for (int v : G[u]) {
        if (v == par) continue;
        dfs(v, u, k+1);
    }
}

int lca(int u, int v) {
    // v を深い方, u を浅い方にする.
    if (depth[u] > depth[v]) swap(u, v);

    // v の深さを u に合わせる.
    for (int k = 0; k < 20 && depth[u] < depth[v]; k++) {
        if ((depth[v] - depth[u]) & (1 << k)) {
            v = p[k][v];
        }
    }

    if (u != v) {
        // u と v が異なるなら, 異なるギリギリまで遡る.
        for (int k = 19; k >= 0; k--) {
            if (p[k][u] != p[k][v]) {
                u = p[k][u];
                v = p[k][v];
            }
        }

        // 一つ遡ってLCAに到達する.
        u = p[0][u];
    }

    return u;
}

int main() {
    cin >> N;
    G.resize(N);
    for (int u = 0; u < N; u++) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int c;
            cin >> c;
            G[u].push_back(c);
            G[c].push_back(u);
        }
    }

    depth.resize(N);
    p.assign(20, vector<int>(N, -1));
    dfs(0, -1, 0);

    // p[k][u] の計算
    for (int k = 1; k < 20; k++) {
        for (int u = 0; u < N; u++) {
            p[k][u] = p[k-1][p[k-1][u]];
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}
