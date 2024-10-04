// https://atcoder.jp/contests/abc220/tasks/abc220_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<ll>> G;
vector<ll> cnt, dp, ans;

void dfs1(ll u, ll p) {
    cnt[u] = 1;
    dp[u] = 0;
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
        dp[u] += dp[v] + cnt[v];
    }
}

void dfs2(ll u, ll p, ll val) {
    ll sum = 0;
    vector<ll> ep(G[u].size(), 0);
    for (int i = 0; i < (int)G[u].size(); i++) {
        ll v = G[u][i];
        if (v == p) ep[i] = val;
        else ep[i] = dp[v] + cnt[v];
        sum += ep[i];
    }
    ans[u] = sum;
    for (int i = 0; i < (int)G[u].size(); i++) {
        ll v = G[u][i];
        if (v == p) continue;
        dfs2(v, u, sum - ep[i] + N - cnt[v]);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp.resize(N);
    cnt.resize(N);
    ans.resize(N);
    dfs1(0, -1);
    dfs2(0, -1, 0);
    for (ll x : ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
