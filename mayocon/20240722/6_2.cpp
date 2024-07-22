// https://atcoder.jp/contests/abc201/tasks/abc201_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = (ll)1e+9 + 7;

ll N;
vector<vector<pair<ll,ll>>> G;

void dfs(ll u, ll par, vector<ll> &B) {
    for (auto &e : G[u]) {
        ll v = e.first, w = e.second;
        if (v == par) continue;
        B[v] = (B[u] ^ w);
        dfs(v, u, B);
    }
}

void solve() {
    cin >> N;
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    mint ans = 0;
    vector<ll> B(N, 0);
    dfs(0, -1, B);

    for (ll k = 0; k < 60; k++) {
        vector<ll> cnt(2, 0);
        mint x = (1LL << k);
        for (ll u = 0; u < N; u++) {
            ans += x * (cnt[0]*(bool)(B[u] & (1LL << k)) + (1 - (bool)(B[u] & (1LL << k)))*cnt[1]);
            cnt[(bool)(B[u] & (1LL << k))]++;
        }
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
