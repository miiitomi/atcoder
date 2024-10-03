// https://atcoder.jp/contests/abc303/tasks/abc303_e
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
vector<ll> dp;
vector<ll> L;

void dfs(ll u, ll p) {
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = dp[v] + 1;
    }
    if (dp[u] % 3 == 1) L.push_back(G[u].size());
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp.assign(N, 0);
    dfs(0, -1);
    sort(L.begin(), L.end());
    for (ll l : L) cout << l << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
