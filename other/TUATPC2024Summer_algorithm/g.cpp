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
vector<ll> compute_d(ll s) {
    vector<ll> d(N, INF);
    d[s] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    Q.push({d[s], s});
    while (!Q.empty()) {
        auto [tmp, u] = Q.top();
        Q.pop();
        if (tmp != d[u]) continue;
        for (auto &e : G[u]) {
            auto [v, c] = e;
            if (d[v] <= d[u]+c) continue;
            d[v] = d[u]+c;
            Q.push({d[v], v});
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
    vector<ll> d = compute_d(0);
    vector<ll> e = compute_d(N-1);
    ll Q;
    cin >> Q;
    vector<vector<ll>> V(Q, {0,0,0});
    for (int i = 0; i < Q; i++) {
        V[i][0] = i;
        cin >> V[i][1];
    }
    sort(V.begin(), V.end(), [](const vector<ll> &l, const vector<ll> &r){return l[1] < r[1];});
    for (int u = 0; u < N; u++) {
        ll t = max(d[u], e[u]);
        ll l = -1, r = Q;
        while (r - l > 1) {
            ll m = (l + r)/2;
            if (V[m][1] < t) l = m;
            else r = m;
        }
        if (r <= Q-1) V[r][2]++;
    }
    for (int i = 0; i < Q-1; i++) V[i+1][2] += V[i][2];
    sort(V.begin(), V.end());
    for (auto &v : V) {
        cout << v[2] << "\n";
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
