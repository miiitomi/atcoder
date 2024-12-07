// https://atcoder.jp/contests/abc164/tasks/abc164_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
template <typename T> bool chmin(T &v, T nv) {
    if (v > nv) {
        v = nv;
        return true;
    }
    return false;
}

struct Edge {
    ll to, silver, time;
    Edge(ll _to, ll _silver, ll _time) {
        to = _to;
        silver = _silver;
        time = _time;
    }
};

void solve() {
    ll N, M, S;
    cin >> N >> M >> S;
    S = min(S, 5000LL);
    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, silver, time;
        cin >> u >> v >> silver >> time;
        u--; v--;
        G[u].push_back(Edge(v, silver, time));
        G[v].push_back(Edge(u, silver, time));
    }
    vector<ll> C(N), D(N);
    for (int i = 0; i < N; i++) cin >> C[i] >> D[i];
    vector<vector<ll>> dp(N, vector<ll>(5001, INF));
    dp[0][S] = 0;
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> Q;
    Q.push({0, {0, S}});
    while (!Q.empty()) {
        ll tmp = Q.top().first;
        auto [i, s] = Q.top().second;
        Q.pop();
        if (dp[i][s] != tmp) continue;
        if (chmin(dp[i][min(s+C[i], 5000LL)], tmp+D[i])) {
            Q.push({dp[i][min(s+C[i], 5000LL)], {i, min(s+C[i], 5000LL)}});
        }
        for (auto &e : G[i]) {
            if (e.silver <= s && chmin(dp[e.to][s - e.silver], tmp+e.time)) {
                Q.push({dp[e.to][s - e.silver], {e.to, s - e.silver}});
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << *min_element(dp[i].begin(), dp[i].end()) << "\n";
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
