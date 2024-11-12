// https://atcoder.jp/contests/abc259/tasks/abc259_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> d;
vector<vector<pair<ll,ll>>> G;
vector<vector<ll>> dp;

void dfs(ll u, ll p) {
    ll tmp = 0;
    priority_queue<ll> Q;
    for (auto &e : G[u]) {
        auto [v, w] = e;
        if (v == p) continue;
        dfs(v, u);
        tmp += dp[v][1];
        Q.push(-dp[v][1]+dp[v][0]+w);
    }
    dp[u] = {tmp, tmp};
    if (d[u] == 0) dp[u][0] = -INF;
    ll cnt = 0;
    while (cnt < d[u] && !Q.empty() && Q.top() > 0) {
        ll x = Q.top();
        Q.pop();
        tmp += x;
        cnt++;
        dp[u][1] = tmp;
        if (cnt < d[u]) dp[u][0] = tmp;
    }
}

void solve() {
    cin >> N;
    d.resize(N);
    for (int i = 0; i < N; i++) cin >> d[i];
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dp.assign(N, vector<ll>(2, 0));
    dfs(0, -1);
    cout << dp[0][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
