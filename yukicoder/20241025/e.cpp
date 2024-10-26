#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
vector<vector<int>> G;
ll ans = 0;
vector<ll> dp;

void dfs(int u, int p) {
    dp[u] = A[u];
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans = (ans + dp[u]*dp[v]%MOD)%MOD;
        dp[u] = (dp[u] + dp[v]*A[u]%MOD)%MOD;
    }
}

void solve() {
    cin >> N;
    A.resize(N);
    for (ll &a : A) cin >> a;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp.resize(N);
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
