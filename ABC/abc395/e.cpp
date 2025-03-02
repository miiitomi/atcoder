#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, X;
    cin >> N >> M >> X;
    vector<vector<pair<ll,ll>>> G(2*N);
    for (int i = 0; i < N; i++) {
        G[2*i].push_back({2*i+1, X});
        G[2*i+1].push_back({2*i, X});
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[2*u].push_back({2*v, 1});
        G[2*v+1].push_back({2*u+1, 1});
    }
    vector<ll> d(2*N, INF);
    d[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({d[0], 0});
    while (!Q.empty()) {
        const auto [tmp, u] = Q.top();
        Q.pop();
        if (tmp != d[u]) continue;
        for (const auto [v, c] : G[u]) {
            if (d[u]+c < d[v]) {
                d[v] = d[u]+c;
                Q.push({d[v], v});
            }
        }
    }

    cout << min(d[2*(N-1)], d[2*(N-1)+1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
