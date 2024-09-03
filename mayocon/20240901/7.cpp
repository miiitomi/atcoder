// https://atcoder.jp/contests/abc287/tasks/abc287_f
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
vector<vector<vector<mint>>> dp;

void dfs(int u, int p) {
    dp[u][0] = {1, 0};
    dp[u][1] = {0, 1};
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        vector<vector<mint>> ndp(2, vector<mint>(dp[u][0].size()+dp[v][0].size()-1, 0));
        for (int k = 0; k < (int)dp[u][0].size(); k++) {
            for (int l = 0; l < (int)dp[v][0].size(); l++) {
                ndp[0][k+l] += dp[u][0][k] * (dp[v][0][l] + dp[v][1][l]);
                ndp[1][k+l] += dp[u][1][k] * dp[v][0][l];
                if (k+l-1 >= 0) ndp[1][k+l-1] += dp[u][1][k] * dp[v][1][l];
            }
        }
        swap(dp[u], ndp);
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
    dp.assign(N, vector<vector<mint>>(2, vector<mint>(0)));
    dfs(0, -1);
    for (int i = 1; i <= N; i++) {
        cout << (dp[0][0][i] + dp[0][1][i]).val() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
