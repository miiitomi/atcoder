// https://atcoder.jp/contests/abc188/tasks/abc188_e
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }

    vector<ll> dp(N, -INF);
    ll ans = -INF;
    for (int i = N-1; i >= 0; i--) {
        for (int v : G[i]) {
            dp[i] = max(dp[i], dp[v]);
        }
        ans = max(ans, dp[i] - A[i]);
        dp[i] = max(dp[i], A[i]);
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
