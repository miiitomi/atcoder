// https://atcoder.jp/contests/abc246/tasks/abc246_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;
vector<vector<ll>> G;
ll x;
vector<ll> dp;

ll dfs(int u, int p) {
    for (int v : G[u]) {
        if (p == v) continue;
        dp[u] += dfs(v, u);
    }
    dp[u] += -(dp[u] > 0) + (A[u] >= x);
    return dp[u];
}

void solve() {
    cin >> N;
    A.assign(N, 0);
    for (int i = 1; i < N; i++) cin >> A[i];
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll left = 0, right = 1e+9 + 1;
    while (right - left > 1) {
        x = (left + right) / 2;
        dp.assign(N, 0);
        if (dfs(0, -1) == 0) right = x;
        else left = x;
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
