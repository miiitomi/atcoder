// https://atcoder.jp/contests/abc223/tasks/abc223_g
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
vector<pair<ll, bool>> dp;
vector<pair<ll, bool>> dp2;

void dfs(int u, int p) {
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u].first += dp[v].first;
        dp[u].second |= dp[v].second;
    }
    if (dp[u].second) {
        dp[u].first++;
        dp[u].second = false;
    } else {
        dp[u].second = true;
    }
}

void dfs2(int u, int p, pair<ll, bool> q) {
    vector<pair<ll,ll>> r((int)G[u].size()+1, make_pair(0, 0));
    for (int i = (int)G[u].size()-1; i >= 0; i--) {
        int v = G[u][i];
        if (v != p) {
            r[i].first += r[i+1].first + dp[v].first;
            r[i].second += r[i+1].second + dp[v].second;
        } else {
            r[i].first += r[i+1].first + q.first;
            r[i].second += r[i+1].second + q.second;
        }
    }
    dp2[u].first = r[0].first;
    if (r[0].second > 0) {
        dp2[u].first++;
        dp2[u].second = false;
    } else {
        dp2[u].second = true;
    }
    pair<ll, ll> tmp = make_pair(0, 0);
    for (int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if (v != p) {
            dfs2(v, u, make_pair(tmp.first+r[i+1].first+(int)(tmp.second+r[i+1].second > 0), (int)(tmp.second+r[i+1].second == 0)));
            tmp.first += dp[v].first;
            tmp.second += dp[v].second;
        } else {
            tmp.first += q.first;
            tmp.second += q.second;
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
    dp.assign(N, make_pair(0, false));
    dfs(0, -1);
    dp2.assign(N, make_pair(0, false));
    dfs2(0, -1, make_pair(0, false));
    ll ans = 0;
    for (int u = 0; u < N; u++) ans += dp2[u].second;
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
