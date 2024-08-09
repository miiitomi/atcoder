// https://atcoder.jp/contests/abc222/tasks/abc222_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<pair<ll,ll>>> G;
vector<ll> D;

vector<ll> farest_point(ll u) {
    vector<ll> d(2*N, INF);
    d[u] = 0;
    queue<ll> Q;
    Q.push(u);
    while (!Q.empty()) {
        ll v = Q.front();
        Q.pop();
        for (auto &e : G[v]) {
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v]+e.second;
                Q.push(e.first);
            }
        }
    }
    return d;
}

void solve() {
    cin >> N;
    G.resize(2*N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    D.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
        G[i].push_back({i+N, D[i]});
        G[N+i].push_back({i, D[i]});
    }
    vector<ll> d0 = farest_point(0);
    ll u = distance(d0.begin(), max_element(d0.begin(), d0.end()));
    vector<ll> du = farest_point(u);
    ll v = distance(du.begin(), max_element(du.begin(), du.end()));
    vector<ll> dv = farest_point(v);

    for (int i = 0; i < N; i++) {
        ll ans = -1;
        if (u-N != i) ans = max(ans, du[i]);
        if (v-N != i) ans = max(ans, dv[i]);
        cout << ans << "\n";
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
