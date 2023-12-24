#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

struct LowLink {
    int N;
    vector<vector<int>> &G;
    vector<bool> reached;
    vector<int> ord, low;
    vector<int> num_change_connections;  // その頂点を除くことによる連結成分数の変化
    vector<pair<int,int>> bridges;  // 橋のvector（その辺を除くと連結成分が増える辺）

    LowLink(vector<vector<int>> &G_): G(G_) {
        N = G.size();
        reached.assign(N, false);
        ord.assign(N, 0);
        low.assign(N, 0);
        num_change_connections.assign(N, 0);
        int k = 0;
        for (int u = 0; u < N; u++) {
            if (!reached[u]) k = dfs(u, k, -1);
        }
    }

    int dfs(int u, int k, int p) {
        if (p == -1) num_change_connections[u] = -1;
        reached[u] = true;
        ord[u] = k;
        k++;
        low[u] = ord[u];
        int num_children = 0;
        for (int v : G[u]) {
            if (!reached[v]) {
                num_children++;
                k = dfs(v, k, u);
                low[u] = min(low[u], low[v]);
                if (ord[u] <= low[v]) num_change_connections[u]++;
                if (ord[u] < low[v]) bridges.push_back(make_pair(u, v));
            } else {
                if (v != p) low[u] = min(low[u], ord[v]);
            }
        }
        return k;
    }
};

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

int H, W;
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return W*x + y;}
vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};

int main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> A(H, vector<int>(W, -1));

    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                A[i][j] = cnt;
                cnt++;
            }
        }
    }

    UnionFind uf(cnt);
    vector<vector<int>> G(cnt);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == -1) continue;
            int s = A[i][j];
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (!is_in(x, y) || A[x][y] == -1) continue;
                int t = A[x][y];
                uf.unite(s, t);
                G[s].push_back(t);
            }
        }
    }

    mint ans = 0;
    mint iv = ((mint)(cnt)).inv();
    set<int> st;
    for (int i = 0; i < cnt; i++) st.insert(uf.root(i));
    int sz = st.size();

    LowLink llk(G);
    for (int i = 0; i < cnt; i++) {
        ans += iv * (sz + llk.num_change_connections[i]);
    }
    cout << ans.val() << endl;
}
