#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct CumulativeSum {
    int N;
    vector<T> data;

    CumulativeSum(vector<T> &A) {
        N = A.size();
        data.assign(N+1, 0);
        for (int i = 0; i < N; i++) data[i+1] = data[i] + A[i];
    }

    T query(int l, int r) {
        // Return Sum of [l, r)
        return data[r]-data[l];
    }
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
    vector<Data> ans;
    vector<vector<Data>> dp;

    /* Set variables and functions below depending on the problem! */
    Data identity = 0;    // TODO: Set DP identity data.
    Data leaf() {return 0;}    // TODO: Set DP data for leaf verteces.
    Data merge(Data a, Data b) {return max(a, b);}    // TODO: Set merge function of two DP data.
    Data apply(Data d_pc, int p, int c, Cost cost) {return d_pc + cost;}    // TODO: Set apply function. d_pc:data(dp[p][c]), p:parent, c:child, cost:edge_cost.
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
    ll N1;
    cin >> N1;
    RerootingTree<ll, ll> rt1(N1);
    for (int i = 0; i < N1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        rt1.add_edge(u, v, 1LL);
    }
    rt1.run();
    ll N2;
    cin >> N2;
    RerootingTree<ll,ll> rt2(N2);
    for (int i = 0; i < N2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        rt2.add_edge(u, v, 1LL);
    }
    rt2.run();
    ll ma = max(*max_element(rt1.ans.begin(), rt1.ans.end()), *max_element(rt2.ans.begin(), rt2.ans.end()));
    vector<ll> tmp1(ma+1, 0), tmp2(ma+1, 0);
    for (ll x: rt1.ans) tmp1[x]++;
    for (ll x: rt2.ans) tmp2[x]++;
    CumulativeSum<ll> cs1(tmp1), cs2(tmp2);

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < N1; i++) {
        ll x = rt1.ans[i];
        ll tmp = cs2.query(ma-x, ma+1);
        cnt += tmp;
        ans += tmp*x;
    }
    for (int i = 0; i < N2; i++) {
        ll x = rt2.ans[i];
        ll tmp = cs1.query(ma-x, ma+1);
        cnt += tmp;
        ans += tmp*x;
    }
    ans += cnt/2;
    ans += (N1*N2 - cnt/2) * ma;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
