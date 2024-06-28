// https://atcoder.jp/contests/abc302/tasks/abc302_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+9;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> G(M+N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        while (a--) {
            ll s;
            cin >> s;
            s--;
            G[s].push_back({M+i, 1});
            G[M+i].push_back({s, 0});
        }
    }

    vector<ll> d(M+N, INF);
    d[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQ;
    PQ.push({d[0], 0});
    while (!PQ.empty()) {
        ll tmp_dist = PQ.top().first, u = PQ.top().second;
        PQ.pop();
        if (d[u] != tmp_dist) continue;
        for (auto &e : G[u]) {
            if (d[e.first] <= d[u] + e.second) continue;
            d[e.first] = d[u]+e.second;
            PQ.push({d[e.first], e.first});
        }
    }

    ll ans = d[M-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans-1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
