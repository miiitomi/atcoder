// https://atcoder.jp/contests/abc248/tasks/abc248_c
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
    vector<vector<mint>> dp(N+1, vector<mint>(K+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int a = 1; a <= M; a++) {
                if (j + a <= K) {
                    dp[i+1][j+a] += dp[i][j];
                }
            }
        }
    }
    mint ans = 0;
    for (int j = 0; j <= K; j++) ans += dp[N][j];
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
