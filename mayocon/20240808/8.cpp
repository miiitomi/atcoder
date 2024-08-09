// https://atcoder.jp/contests/abc362/tasks/abc362_f
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
vector<ll> cnt;
vector<ll> V;

void dfs1(ll u, ll p) {
    cnt[u] = 1;
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
    }
}

void dfs2(ll u, ll p) {
    for (ll v : G[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
    V.push_back(u);
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
    cnt.resize(N);
    dfs1(0, -1);
    ll u = 0, p = -1;
    while (true) {
        ll mv = 0, nxt = -1;
        for (ll v : G[u]) {
            if (p == v) continue;
            if (mv < cnt[v]) {
                mv = cnt[v];
                nxt = v;
            }
        }
        if (mv <= N/2) break;
        p = u; u = nxt;
    }
    dfs2(u, -1);
    if (V.size()%2 == 1) V.pop_back();
    for (int i = 0; i < N/2; i++) {
        cout << V[i]+1 << " " << V[i+N/2]+1 << "\n";
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
