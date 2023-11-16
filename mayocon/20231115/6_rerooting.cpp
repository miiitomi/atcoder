// https://atcoder.jp/contests/abc222/tasks/abc222_f
// 全方位木DPを用いた解法
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    Data identity = 0;
    Data leaf() {return 0;}
    Data merge(Data a, Data b) {return max(a, b);}
    Data apply(Data d_pc, int p, int c, Cost cost) {return max(d_pc, D[c])+ cost;}    // TODO: set apply function. x:data(dp[p][c]), p:parent, c:child, cost:edge_cost.

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

int main() {
    int N;
    cin >> N;
    RerootingTree<ll, ll> rt(N);
    for (int i = 0; i < N-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        rt.add_edge(u, v, c);
    }
    D.resize(N);
    for (int i = 0; i < N; i++) cin >> D[i];

    rt.run();
    for (int i = 0; i < N; i++) cout << rt.ans[i] << endl;
}
