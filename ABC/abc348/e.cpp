#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

vector<ll> C;

struct dta {
    ll sum_cost;
    ll score;
    dta(ll _sum_cost, ll _score): sum_cost(_sum_cost), score(_score) {};
};

template <typename Cost, typename Data>
struct RerootingTree {
    template<typename C> struct Edge {
        int to;
        C cost;

        Edge(int t, C c = 1): to(t), cost(c) {}
    };
    int N;
    vector<vector<Edge<Cost>>> G;
    vector<ll> ans;
    vector<vector<Data>> dp;

    /* Set variables and functions below depending on the problem! */
    Data identity = dta(0, 0);    // TODO: Set DP identity data.
    Data merge(Data a, Data b) {return dta(a.sum_cost + b.sum_cost, a.score + b.score);}    // TODO: Set merge function of two DP data.
    Data apply(Data d_pc) {
        d_pc.score += d_pc.sum_cost;
        return d_pc;
    }    // TODO: Set apply function. d_pc:data(dp[p][c]), p:parent, c:child, cost:edge_cost.
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
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to == par) continue;
            dp[v][i] = dfs1(e.to, v);
            dp_cum = merge(dp_cum, apply(dp[v][i]));
        }
        dp_cum.sum_cost += C[v];
        return dp_cum;
    }

    void dfs2(int v, Data val, int par) {
        int degree = G[v].size();
        vector<Data> dp_l(degree+1, identity), dp_r(degree+1, identity);
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to == par) dp[v][i] = val;
            dp_l[i+1] = merge(dp_l[i], apply(dp[v][i]));
        }
        for (int i = degree-1; i >= 0; i--) {
            dp_r[i] = merge(dp_r[i+1], apply(dp[v][i]));
        }
        ans[v] = dp_l[degree].score;
        for (int i = 0; i < degree; i++) {
            Edge<Cost> &e = G[v][i];
            if (e.to != par) dfs2(e.to, merge(dta(C[v], 0), merge(dp_l[i], dp_r[i+1])), v);
        }
    }

    void run() {
        dp.resize(N);
        ans.assign(N, 0);
        dfs1(0, -1);
        dfs2(0, identity, -1);
    }
};

void solve() {
    int N;
    cin >> N;
    RerootingTree<ll, dta> rt(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        rt.add_edge(a, b);
    }
    C.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    rt.run();
    cout << *min_element(rt.ans.begin(), rt.ans.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}