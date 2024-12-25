// https://atcoder.jp/contests/abc212/tasks/abc212_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> U(M), V(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
    }
    for (int i = 0; i < N; i++) {
        U.push_back(i);
        V.push_back(i);
        M++;
    }
    vector<vector<mint>> dp(K+1, vector<mint>(N, 0));
    dp[0][0] = 1;
    for (int i = 0; i < K; i++) {
        mint sum = 0;
        for (int j = 0; j < N; j++) sum += dp[i][j];
        dp[i+1] = vector<mint>(N, sum);
        for (int k = 0; k < M; k++) {
            int u = U[k], v = V[k];
            dp[i+1][u] -= dp[i][v];
            if (u != v) dp[i+1][v] -= dp[i][u];
        }
    }
    cout << dp[K][0].val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
