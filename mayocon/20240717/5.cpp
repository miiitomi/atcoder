// https://atcoder.jp/contests/abc357/tasks/abc357_e
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
    scc_graph G(N);
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        G.add_edge(i, a[i]);
    }
    vector<vector<int>> scc = G.scc();
    vector<ll> dp(N, 0);
    for (int j = (int)scc.size()-1; j >= 0; j--) {
        vector<int> &V = scc[j];
        if ((int)V.size() >= 2) {
            for (int x : V) dp[x] = V.size();
        } else {
            int u = V[0];
            dp[u] = 1 + dp[a[u]];
        }
    }
    ll ans = 0;
    for (ll u = 0; u < N; u++) ans += dp[u];
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
