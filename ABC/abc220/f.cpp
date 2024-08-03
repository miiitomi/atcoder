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
vector<ll> siz, dp, ans;

void dfs1(ll u, ll p) {
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        dp[u] += dp[v] + siz[v];
    }
    siz[u]++;
}

void dfs2(ll u, ll p, ll d, ll s) {
    vector<ll> siz_r(G[u].size()+1, 0), dp_r(G[u].size()+1, 0);
    for (int i = G[u].size()-1; i >= 0; i--) {
        ll v = G[u][i];
        if (v == p) {
            siz_r[i] = siz_r[i+1] + s;
            dp_r[i] = dp_r[i+1] + d;
        } else {
            siz_r[i] = siz_r[i+1] + siz[v];
            dp_r[i] = dp_r[i+1] + dp[v];
        }
    }
    ans[u] = dp_r[0] + siz_r[0];
    ll tmp_d = 0, tmp_s = 0;
    for (int i = 0; i < (int)G[u].size(); i++) {
        ll v = G[u][i];
        if (v == p) {
            tmp_d += d;
            tmp_s += s;
        } else {
            dfs2(v, u, tmp_d + dp_r[i+1] + tmp_s + siz_r[i+1], tmp_s + siz_r[i+1] + 1);
            tmp_d += dp[v];
            tmp_s += siz[v];
        }
    }
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
    siz.assign(N, 0);
    dp.assign(N, 0);
    dfs1(0, -1);

    ans.assign(N, 0);
    dfs2(0, -1, 0, 0);
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
