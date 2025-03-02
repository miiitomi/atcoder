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
vector<int> dp;
int ans = -1;

void dfs(int u, int p) {
    dp[u] = 1 + (int)(u != 0);

    vector<int> tmp;
    while (!G[u].empty()) {
        int v = G[u].back();
        G[u].pop_back();
        if (v == p) continue;
        tmp.push_back(v);
        dfs(v, u);
    }
    swap(G[u], tmp);

    if ((int)G[u].size() >= 3 + (int)(u==0)) {
        sort(G[u].begin(), G[u].end(), [&](const int &l, const int &r) {return dp[l] > dp[r];});
        for (int j = 0; j < 3+(u==0); j++) dp[u] += dp[G[u][j]]-1;
        if (u != 0 && (int)G[u].size() >= 4) ans = max(ans, dp[u]+dp[G[u][3]]-2);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }
    dp.resize(N);
    dfs(0, -1);

    ans = max(ans, *max_element(dp.begin(), dp.end()));
    if (ans < 4) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
