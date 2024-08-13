// https://atcoder.jp/contests/abc221/tasks/abc221_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<ll>> G;

vector<pair<ll,ll>> compute_distance(ll s) {
    vector<pair<ll,ll>> dist(N, {INF, -1});
    dist[s] = {0, -1};
    queue<ll> Q;
    Q.push(s);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (dist[v].first != INF) continue;
            dist[v] = {dist[u].first+1, u};
            Q.push(v);
        }
    }
    return dist;
}

ll dfs1(ll u, ll p, ll md, ll d) {
    ll ans = (d == md);
    for (ll v : G[u]) {
        if (v == p) continue;
        ans += dfs1(v, u, md, d+1);
    }
    return ans;
}

void even(ll r, ll md) {
    mint ans = 1, cnt = 0;
    for (ll v : G[r]) {
        ll res = dfs1(v, r, md, 1);
        ans *= (res+1);
        cnt += res;
    }
    cout << (ans - 1 - cnt).val() << endl;
    return;
}

void odd(ll v, ll u, ll md) {
    mint ans = (mint)dfs1(v, u, md, 0) * (mint)dfs1(u, v, md, 0);
    cout << ans.val() << endl;
    return;
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto res = compute_distance(0);
    ll u = distance(res.begin(), max_element(res.begin(), res.end()));
    res = compute_distance(u);
    ll v = distance(res.begin(), max_element(res.begin(), res.end()));

    if (res[v].first % 2 == 0) {
        ll md = res[v].first/2;
        while (res[v].first > md) v = res[v].second;
        even(v, md);
    } else {
        ll md = res[v].first/2;
        for (int k = 0; k < md; k++) v = res[v].second;
        u = res[v].second;
        odd(v, u, md);
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
