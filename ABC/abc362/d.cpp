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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    vector<ll> d(N, INF);
    d[0] = A[0];
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({A[0], 0});
    while (!Q.empty()) {
        auto [tmp, u] = Q.top();
        Q.pop();
        if (tmp != d[u]) continue;
        for (auto &e : G[u]) {
            ll v = e.first, w = e.second;
            if (d[v] > d[u] + w + A[v]) {
                d[v] = d[u] + w + A[v];
                Q.push({d[v], v});
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << d[i] << " ";
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
