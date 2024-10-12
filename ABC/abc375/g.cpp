#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

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

vector<ll> compute_dist(int s, vector<vector<pair<int,ll>>> &G) {
    vector<ll> d(G.size(), INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    d[s] = 0;
    Q.push({0, s});
    while (!Q.empty()) {
        auto [tmp, u] = Q.top();
        Q.pop();
        if (tmp != d[u]) continue;
        for (auto &e : G[u]) {
            auto [v, c] = e;
            if (d[v] > tmp + c) {
                d[v] = tmp + c;
                Q.push({d[v], v});
            }
        }
    }
    return d;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> ans(M, "No");
    map<pair<int,int>, int> mp;
    vector<vector<pair<int,ll>>> G(N);
    vector<int> A(M), B(M);
    vector<ll> C(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        A[i] = a; B[i] = b; C[i] = c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        mp[{a, b}] = i;
    }
    vector<ll> d_0 = compute_dist(0, G), d_N = compute_dist(N-1, G);
    vector<vector<int>> H(N);
    for (int i = 0; i < M; i++) {
        int a = A[i], b = B[i], c = C[i];
        if (d_0[N-1] == min(d_0[a]+c+d_N[b], d_0[b]+c+d_N[a])) {
            H[a].push_back(b);
            H[b].push_back(a);
        }
    }
    LowLink lowlink(H);
    for (auto &p : lowlink.bridges) {
        pair<int,int> q = {min(p.first,p.second), max(p.first, p.second)};
        ans[mp[q]] = "Yes";
    }
    for (auto &s : ans) cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
