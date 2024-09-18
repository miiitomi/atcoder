// https://atcoder.jp/contests/abc204/tasks/abc204_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<vector<ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        G[a].push_back({b, c, d});
        G[b].push_back({a, c, d});
    }
    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (d != dist[u]) continue;
        for (vector<ll> &v : G[u]) {
            ll to = v[0], C = v[1], D = v[2];
            ll min_t = -1, min_v = INF;
            for (ll t = max(0LL, (ll)round(sqrt(D))-1-3); t <= (ll)round(sqrt(D))-1+3; t++) {
                ll T = t + C + D/(t+1);
                if (min_v > T) {
                    min_t = t;
                    min_v = T;
                }
            }
            ll t = max(min_t, d);
            ll tmp = t + C + D/(t+1);
            if (dist[to] > tmp) {
                dist[to] = tmp;
                Q.push({tmp, to});
            }
        }
    }

    if (dist[N-1] == INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
