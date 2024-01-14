#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int N;
vector<vector<int>> G;
vector<bool> r;
vector<vector<ll>> dp;

void dfs(int u, int par) {
    if (par != -1 && G[u].size() == 1) {
        if (r[u]) dp[u][0] = 1;
        else dp[u][1] = 1;
        return;
    }

    ll x=1, y=1, z=1;
    for (int v : G[u]) {
        if (v == par) continue;
        dfs(v, u);
        x = x * (dp[v][0] + dp[v][2]) % MOD;
        y = y * (dp[v][1] + dp[v][2]) % MOD;
        z = z * (dp[v][0] + dp[v][1] + 2*dp[v][2]) % MOD;
    }

    if (r[u]) {
        dp[u][0] = x;
        dp[u][2] = (z - x + MOD) % MOD;
    } else {
        dp[u][1] = y;
        dp[u][2] = (z - y + MOD) % MOD;
    }
    return;
}

int main() {
    cin >> N;
    r.resize(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        r[i] = (c == 'a');
    }

    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dp.assign(N, vector<ll>(3, 0));

    dfs(0, -1);
    cout << dp[0][2] << endl;
}
