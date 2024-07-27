#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
bool chmin(ll &l, ll r) {if (l > r) {l = r; return true;} else return false;}

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<ll,ll>>> G(N);
    for (int m = 0; m < M; m++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<vector<ll>> dp((1LL << (K-1)), vector<ll>(N, INF));
    for (ll u = 0; u < K-1; u++) dp[1LL << u][u] = 0;
    for (ll s = 0; s < (1LL << (K-1)); s++) {
        for (ll t = (s-1)&s; t > 0; t = (t-1)&s) {
            for (ll u = 0; u < N; u++) {
                chmin(dp[s][u], dp[t][u]+dp[s-t][u]);
            }
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
        for (ll u = 0; u < N; u++) PQ.push({dp[s][u], u});
        while (!PQ.empty()) {
            auto [d, u] = PQ.top();
            PQ.pop();
            if (d != dp[s][u]) continue;
            for (auto &e : G[u]) {
                if (chmin(dp[s][e.first], dp[s][u]+e.second)) {
                    PQ.push({dp[s][e.first], e.first});
                }
            }
        }
    }

    ll s = (1LL << (K-1))-1;
    for (int u = K-1; u < N; u++) cout << dp[s][u] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
