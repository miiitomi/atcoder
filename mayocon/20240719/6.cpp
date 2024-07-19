// https://atcoder.jp/contests/abc190/tasks/abc190_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> compute_distance(vector<vector<ll>> &G, ll s) {
    vector<ll> d((int)G.size(), INF);
    d[s] = 0;
    queue<ll> Q;
    Q.push(s);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (d[v] > d[u]+1) {
                d[v] = d[u]+1;
                Q.push(v);
            }
        }
    }
    return d;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll K;
    cin >> K;
    vector<ll> C(K);
    vector<vector<ll>> d(K);
    for (int i = 0; i < K; i++) {
        cin >> C[i];
        C[i]--;
        d[i] = compute_distance(G, C[i]);
    }

    vector<vector<ll>> dp((1<<K), vector<ll>(K, INF));
    for (int k = 0; k < K; k++) dp[(1 << k)][k] = 1;
    for (ll s = 1; s < (1 << K); s++) {
        for (ll k = 0; k < K; k++) {
            if (dp[s][k] >= INF) continue;
            for (ll l = 0; l < K; l++) {
                dp[s | (1 << l)][l] = min(dp[s | (1 << l)][l], dp[s][k] + d[k][C[l]]);
            }
        }
    }

    ll ans = INF;
    for (ll k = 0; k < K; k++) ans = min(ans, dp[(1LL << K)-1][k]);
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
