// https://atcoder.jp/contests/abc201/tasks/abc201_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e+9 + 7;

int N;
vector<vector<pair<int,ll>>> G;

void dfs(int u, int p, vector<ll> &d) {
    for (auto &e : G[u]) {
        if (e.first == p) continue;
        d[e.first] = d[u] ^ e.second;
        dfs(e.first, u, d);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    vector<ll> d(N, 0);
    dfs(0, -1, d);
    ll ans = 0;
    for (int k = 0; k < 62; k++) {
        ll cnt = 0;
        for (int i = 0; i < N; i++) cnt += (bool)(d[i] & (1LL << k));
        ans = (ans + cnt*(N-cnt)%MOD*((1LL << k) % MOD)%MOD) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
