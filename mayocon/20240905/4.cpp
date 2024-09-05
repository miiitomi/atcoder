// https://atcoder.jp/contests/abc244/tasks/abc244_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--; T--; X--;
    vector<vector<int>> G(N), H(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        H[u][v] = 1;
        H[v][u] = 1;
    }

    vector<vector<mint>> dp(2, vector<mint>(N, 0));
    dp[0][S] = 1;

    for (int k = 0; k < K-1; k++) {
        vector<vector<mint>> ndp(2, vector<mint>(N, 0));
        for (int l = 0; l < 2; l++) {
            for (int u = 0; u < N; u++) {
                for (int v : G[u]) {
                    if (v == X) ndp[l^1][v] += dp[l][u];
                    else ndp[l][v] += dp[l][u];
                }
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for (int u = 0; u < N; u++) {
        if (H[u][T]) ans += dp[0][u];
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
