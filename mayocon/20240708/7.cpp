// https://atcoder.jp/contests/abc245/tasks/abc245_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, K, L;
    cin >> N >> M >> K >> L;
    vector<ll> A(N), B(L);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<pair<ll,ll>>> dp(N, vector<pair<ll,ll>>(2, {INF, -1}));
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> PQ;
    for (int i = 0; i < L; i++) {
        cin >> B[i];
        B[i]--;
        dp[B[i]][0] = {0, A[B[i]]};
        PQ.push({0, {B[i], A[B[i]]}});
    }
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    while (!PQ.empty()) {
        ll tmp_d = PQ.top().first, u = PQ.top().second.first, c = PQ.top().second.second;
        PQ.pop();
        if (dp[u][0] != make_pair(tmp_d, c) && dp[u][1] != make_pair(tmp_d, c)) continue;
        for (auto &e : G[u]) {
            ll v = e.first, cost = e.second;
            if (dp[v][0].second == c) {
                if (dp[v][0].first <= tmp_d + cost) continue;
                dp[v][0].first = tmp_d + cost;
                PQ.push({tmp_d + cost, {v, c}});
            } else if (dp[v][1].second == c) {
                if (dp[v][1].first <= tmp_d + cost) continue;
                dp[v][1].first = tmp_d + cost;
                if (tmp_d+cost < dp[v][0].first) swap(dp[v][0], dp[v][1]);
                PQ.push({tmp_d + cost, {v, c}});
            } else if (tmp_d + cost < dp[v][0].first) {
                dp[v][1] = dp[v][0];
                dp[v][0] = {tmp_d+cost, c};
                PQ.push({tmp_d + cost, {v, c}});
            } else if (tmp_d + cost < dp[v][1].first) {
                dp[v][1] = {tmp_d+cost, c};
                PQ.push({tmp_d + cost, {v, c}});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        ll ans = INF;
        if (dp[i][0].second != A[i]) ans = min(ans, dp[i][0].first);
        if (dp[i][1].second != A[i]) ans = min(ans, dp[i][1].first);
        if (ans == INF) ans = -1;
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
