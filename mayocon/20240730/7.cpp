// https://atcoder.jp/contests/abc160/tasks/abc160_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);

ll N;
vector<vector<ll>> G;
vector<ll> siz;
vector<mint> dp;
vector<mint> ans;

void dfs1(ll u, ll p) {
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        dp[u] *= dp[v] * F[siz[v]].inv();
    }
    dp[u] *= F[siz[u]];
    siz[u]++;
}

void dfs2(ll u, ll p, pair<ll,mint> val) {
    vector<ll> siz_l(G[u].size()+1, 0), siz_r(G[u].size()+1, 0);
    vector<mint> dp_l(G[u].size()+1, 1), dp_r(G[u].size()+1, 1);
    for (int i = 0; i < (int)G[u].size(); i++) {
        ll v = G[u][i];
        if (v == p) {
            siz_l[i+1] = siz_l[i] + val.first;
            dp_l[i+1] = dp_l[i] * val.second * F[val.first].inv();
        } else {
            siz_l[i+1] = siz_l[i] + siz[v];
            dp_l[i+1] = dp_l[i] * dp[v] * F[siz[v]].inv();
        }
        v = G[u][G[u].size()-1-i];
        if (v == p) {
            siz_r[G[u].size()-1-i] = siz_r[G[u].size()-i] + val.first;
            dp_r[G[u].size()-1-i] = dp_r[G[u].size()-i] * val.second * F[val.first].inv();
        } else {
            siz_r[G[u].size()-1-i] = siz_r[G[u].size()-i] + siz[v];
            dp_r[G[u].size()-1-i] = dp_r[G[u].size()-i] * dp[v] * F[siz[v]].inv();
        }
    }
    ans[u] = dp_l[G[u].size()] * F[siz_l[G[u].size()]];
    for (int i = 0; i < (int)G[u].size(); i++) {
        ll v = G[u][i];
        if (v == p) continue;
        dfs2(v, u, make_pair(N-siz[v], dp_l[i]*dp_r[i+1]*F[siz_l[i]+siz_r[i+1]]));
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
    dp.assign(N, 1);
    dfs1(0, -1);

    ans.assign(N, 0);
    dfs2(0, -1, make_pair(0, (mint)1));
    for (mint &x : ans) {
        cout << x.val() << "\n";
    }
}

int main() {
    for (ll x = 1; x < (ll)1e+6; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
