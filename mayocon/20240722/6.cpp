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
vector<vector<pair<int, ll>>> G;
mint ans = 0;

vector<vector<ll>> cnt;
void dfs(ll u, ll par, ll k) {
    cnt[u] = {0, 0};
    for (auto &e : G[u]) {
        ll v = e.first, w = e.second;
        if (v == par) continue;
        dfs(v, u, k);
        if (w & (1LL << k)) {
            cnt[u][0] += cnt[v][1];
            cnt[u][1] += cnt[v][0];
        } else {
            cnt[u][0] += cnt[v][0];
            cnt[u][1] += cnt[v][1];
        }
    }

    for (auto &e : G[u]) {
        ll v = e.first, w = e.second;
        if (v == par) continue;
        ll p = cnt[v][0], q = cnt[v][1];
        if (w & (1LL << k)) swap(p, q);
        ans += 2*q*((1LL << k)%MOD)%MOD;
        ans += ((p * (cnt[u][1] - q))%MOD) * ((1LL << k)%MOD) % MOD;
        ans += ((q * (cnt[u][0] - p))%MOD) * ((1LL << k)%MOD) % MOD;
    }

    cnt[u][0]++;
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
    cnt.assign(N, vector<ll>(2, 0));

    for (ll k = 0; k <= 60; k++) dfs(0, -1, k);
    ans /= 2;
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
