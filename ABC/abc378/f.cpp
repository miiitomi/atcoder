#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<vector<int>> G;
vector<ll> dp;
ll ans = 0;

void dfs(int u, int p) {
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        if ((int)G[u].size() == 2) {
            ans += dp[v];
        } else if ((int)G[u].size() == 3) {
            ans += dp[u]*(dp[v]+((int)G[v].size()==2));
            dp[u] += dp[v] + ((int)G[v].size() == 2);
        }
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp.assign(N, 0);
    dfs(0, -1);
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
