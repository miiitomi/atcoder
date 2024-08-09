// https://atcoder.jp/contests/abc222/tasks/abc222_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<pair<ll,ll>>> G;
vector<ll> D;
vector<ll> dp;
vector<ll> ans;

void dfs1(ll u, ll p) {
    dp[u] = 0;
    for (auto &e : G[u]) {
        if (e.first == p) continue;
        dfs1(e.first, u);
        dp[u] = max(dp[u], max(dp[e.first], D[e.first]) + e.second);
    }
}

void dfs2(ll u, ll p, ll val) {
    vector<ll> tmp(G[u].size()+1, 0);
    for (int i = G[u].size()-1; i >= 0; i--) {
        auto [v, c] = G[u][i];
        if (v == p) tmp[i] = max(tmp[i+1], val);
        else tmp[i] = max(tmp[i+1], max(dp[v], D[v])+c);
    }
    ans[u] = tmp[0];
    ll left = 0;
    for (int i = 0; i < (int)G[u].size(); i++) {
        auto [v, c] = G[u][i];
        if (v != p) {
            dfs2(v, u, max(max(left, tmp[i+1]), D[u]) + c);
            left = max(left, max(dp[v], D[v])+c);
        } else {
            left = max(left, val);
        }
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    D.resize(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    dp.assign(N, 0);
    dfs1(0, -1);
    ans.assign(N, 0);
    dfs2(0, -1, 0);

    for (int i = 0; i < N; i++) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
