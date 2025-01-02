// https://atcoder.jp/contests/typical90/tasks/typical90_m
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<pair<ll,ll>>> G;

vector<ll> dijkstra(int s) {
    vector<ll> d(N, INF);
    d[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({d[s], s});
    while (!Q.empty()) {
        auto [c, u] = Q.top();
        Q.pop();
        if (c != d[u]) continue;
        for (auto &e : G[u]) {
            if (d[e.first] > c + e.second) {
                d[e.first] = c + e.second;
                Q.push({d[e.first], e.first});
            }
        }
    }
    return d;
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    vector<ll> d = dijkstra(0), e = dijkstra(N-1);
    for (int k = 0; k < N; k++) {
        cout << d[k]+e[k] << "\n";
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
