// https://atcoder.jp/contests/abc143/tasks/abc143_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, L;
    cin >> N >> M >> L;
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (c > L) continue;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<vector<pair<ll,ll>>> dp(N, vector<pair<ll,ll>>(N, {INF, INF}));
    for (ll s = 0; s < N; s++) {
        dp[s][s] = {0LL, 0LL};
        priority_queue<pair<pair<ll,ll>, ll>, vector<pair<pair<ll,ll>, ll>>, greater<pair<pair<ll,ll>, ll>>> Q;
        Q.push({{0LL, 0LL}, s});
        while (!Q.empty()) {
            auto [p, u] = Q.top();
            Q.pop();
            if (dp[s][u] != p) continue;
            auto [k, l] = p;
            for (auto e : G[u]) {
                auto [v, c] = e;
                pair<ll,ll> q = {k, l+c};
                if (q.second > L) {
                    q.first++;
                    q.second = c;
                }
                if (dp[s][v] <= q) continue;
                dp[s][v] = q;
                Q.push({q, v});
            }
        }
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll s, t;
        cin >> s >> t;
        s--; t--;
        auto [k, l] = dp[s][t];
        if (k == INF) cout << -1 << "\n";
        else cout << k << "\n";
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
