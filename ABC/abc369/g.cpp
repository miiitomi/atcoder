#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<vector<pair<ll,ll>>> G;
vector<ll> V;
vector<ll> dp;

void dfs(ll u, ll par) {
    vector<ll> w;
    for (pair<ll,ll> &p : G[u]) {
        auto [v, l] = p;
        if (v == par) continue;
        dfs(v, u);
        w.push_back(2*l + dp[v]);
    }
    if (!w.empty()) {
        sort(w.begin(), w.end());
        dp[u] = w.back();
        w.pop_back();
        for (ll x : w) V.push_back(x);
    }
}

void solve() {
    ll N;
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        G[u].push_back({v, l});
        G[v].push_back({u, l});
    }
    dp.assign(N, 0);
    dfs(0, -1);
    V.push_back(dp[0]);
    while ((int)V.size() < N) V.push_back(0);
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    ll ans = 0;
    for (ll v : V) {
        ans += v;
        cout << ans << "\n";
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
