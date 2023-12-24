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