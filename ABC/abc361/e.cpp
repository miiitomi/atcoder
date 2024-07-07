#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<ll> compute_distance(ll s, vector<vector<pair<ll,ll>>> &G) {
    ll N = G.size();
    vector<ll> d(N, INF);
    d[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({d[s], s});
    while (!Q.empty()) {
        auto [tmp_d, u] = Q.top();
        Q.pop();
        if (tmp_d != d[u]) continue;
        for (auto &e : G[u]) {
            if (d[e.first] > d[u] + e.second) {
                d[e.first] = d[u] + e.second;
                Q.push({d[e.first], e.first});
            }
        }
    }
    return d;
}

void solve() {
    ll N;
    cin >> N;
    vector<vector<pair<ll,ll>>> G(N);
    ll ans = 0;
    for (int k = 0; k < N-1; k++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        ans += 2*c;
    }
    vector<ll> d = compute_distance(0, G);
    int u = distance(d.begin(), max_element(d.begin(), d.end()));
    d = compute_distance(u, G);
    ll t = *max_element(d.begin(), d.end());
    ans -= t;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
