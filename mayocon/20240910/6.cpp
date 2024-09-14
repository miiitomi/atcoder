// https://atcoder.jp/contests/abc251/tasks/abc251_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<ll>> G;
vector<pair<ll,ll>> T1, T2;

void dfs(ll u, vector<bool> &reached) {
    for (ll v : G[u]) {
        if (reached[v]) continue;
        reached[v] = true;
        T1.push_back({u, v});
        dfs(v, reached);
    }
}

void bfs() {
    queue<ll> Q;
    Q.push(0);
    vector<bool> reached(N, false);
    reached[0] = true;
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (reached[v]) continue;
            reached[v] = true;
            T2.push_back({u, v});
            Q.push(v);
        }
    }
}

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> reached(N, false);
    reached[0] = true;
    dfs(0, reached);

    for (auto &p: T1) cout << p.first+1 << " " << p.second+1 << "\n";

    bfs();
    for (auto &p: T2) cout << p.first+1 << " " << p.second+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
