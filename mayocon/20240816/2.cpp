// https://atcoder.jp/contests/abc262/tasks/abc262_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N, 0));
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    ll ans = 0;
    for (ll a = 0; a < N; a++) {
        for (ll b = a+1; b < N; b++) {
            for (ll c = b+1; c < N; c++) {
                if (G[a][b] && G[b][c] && G[c][a]) ans++;
            }
        }
    }
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
