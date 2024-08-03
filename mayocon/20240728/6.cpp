// https://atcoder.jp/contests/abc202/tasks/abc202_e
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
ll Q;
vector<ll> ans;
vector<vector<pair<ll,ll>>> Query;
vector<ll> cnt;

void dfs(int u, int p, int d) {
    for (auto &e: Query[u]) {
        ans[e.first] -= cnt[e.second];
    }
    cnt[d]++;
    for (int v : G[u]) {
        if (v != p) dfs(v, u, d+1);
    }
    for (auto &e: Query[u]) {
        ans[e.first] += cnt[e.second];
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 1; i < N; i++) {
        ll p;
        cin >> p;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    cin >> Q;
    ans.assign(Q, 0);
    Query.resize(N);
    for (int i = 0; i < Q; i++) {
        ll u, d;
        cin >> u >> d;
        u--;
        Query[u].push_back({i, d});
    }
    cnt.assign(N, 0);
    dfs(0, -1, 0);

    for (ll x : ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
