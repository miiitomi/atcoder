// https://atcoder.jp/contests/abc364/tasks/abc364_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool chmin(ll &l, ll r) {
    if (l > r) {
        l = r;
        return true;
    }
    return false;
}

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    vector<vector<ll>> dp(1LL << (K-1), vector<ll>(N, INF));
    for (ll u = 0; u < K-1; u++) dp[1 << u][u] = 0;
    for (ll s = 1; s < (1 << (K-1)); s++) {
        for (ll t = (s-1)&s; t > 0; t = (t-1)&s) {
            for (ll u = 0; u < N; u++) chmin(dp[s][u], dp[t][u]+dp[s-t][u]);
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
        for (ll u = 0; u < N; u++) Q.push({dp[s][u], u});
        while (!Q.empty()) {
            auto [tmp_d, u] = Q.top();
            Q.pop();
            if (tmp_d != dp[s][u]) continue;
            for (auto &e : G[u]) {
                if (chmin(dp[s][e.first], dp[s][u] + e.second)) {
                    Q.push({dp[s][e.first], e.first});
                }
            }
        }
    }

    for (ll u = K-1; u < N; u++) {
        cout << dp[(1 << (K-1))-1][u] << "\n";
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
