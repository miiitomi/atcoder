#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> U(N-1), V(N-1);
    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        int &u = U[i], &v = V[i];
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dsu d(N);
    for (int i = 0; i < N-1; i++) {
        int u = U[i], v = V[i];
        if (G[u].size() == 3 && G[v].size() == 3) {
            d.merge(u, v);
        }
    }
    vector<ll> cnt(N, 0);
    for (int u = 0; u < N; u++) {
        if (G[u].size() != 2) continue;
        for (int v : G[u]) {
            if (G[v].size() != 3) continue;
            int r = d.leader(v);
            cnt[r]++;
        }
    }
    ll ans = 0;
    for (ll c : cnt) ans += c*(c-1)/2;
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
