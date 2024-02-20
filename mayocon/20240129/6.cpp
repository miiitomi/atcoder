// https://atcoder.jp/contests/abc222/tasks/abc222_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<ll> D;


template <typename Cost, typename Data>
struct RerootingTree {
    template<typename C> struct Edge {
        int to;
        C cost;

        Edge(int t, C c = 1): to(t), cost(c) {}
    };
    int N;
    vector<vector<Edge<Cost>>> G;
    vector<Data> ans;
    vector<vector<Data>> dp;

    /* Set variables and functions below depending on the problem! */
    Data identity = 0;    // TODO: Set DP identity data.
    Data leaf() {return 0;}    // TODO: Set DP data for leaf verteces.
    Data merge(Data a, Data b) {return max(a, b);}    // TODO: Set merge function of two DP data.
    Data apply(Data d_pc, int p, int c, Cost cost) {return max(D[c], d_pc) + cost;}    // TODO: Set apply function. d_pc:data(dp[p][c]), p:parent, c:child, cost:edge_cost.
    /* Up to here! */

    RerootingTree(int n) {
        N = n;
        G.resize(n);
    }

    void add_edge(int u, int v, Cost c = 1) {
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    Data dfs1(int v, int par) {
        int degree = G[v].size();
        dp[v].assign(degree, identity);
        Data dp_cum = identity;
        bool updated = false;
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to == par) continue;
            dp[v][i] = dfs1(e.to, v);
            dp_cum = merge(dp_cum, apply(dp[v][i], v, e.to, e.cost));
            updated = true;
        }
        if (updated) return dp_cum;
        else return leaf();
    }

    void dfs2(int v, Data val, int par) {
        int degree = G[v].size();
        vector<Data> dp_l(degree+1, identity), dp_r(degree+1, identity);
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to == par) dp[v][i] = val;
            dp_l[i+1] = merge(dp_l[i], apply(dp[v][i], v, e.to, e.cost));
        }
        for (int i = degree-1; i >= 0; i--) {
            Edge<Cost> &e = G[v][i];
            dp_r[i] = merge(dp_r[i+1], apply(dp[v][i], v, e.to, e.cost));
        }
        ans[v] = dp_l[degree];
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to != par) dfs2(e.to, merge(dp_l[i], dp_r[i+1]), v);
        }
    }

    void run() {
        dp.resize(N);
        ans.assign(N, identity);
        dfs1(0, -1);
        dfs2(0, identity, -1);
    }
};


void solve() {
    cin >> N;
    RerootingTree<ll, ll> rt(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll c;
        cin >> c;
        rt.add_edge(u, v, c);
    }
    D.resize(N);
    for (int i = 0; i < N; i++) cin >> D[i];

    rt.run();
    for (ll v : rt.ans) cout << v << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}