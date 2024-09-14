// https://atcoder.jp/contests/abc046/tasks/abc046_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;

    vector<vector<ll>> dp(N, vector<ll>(K, 0));
    dp[0] = vector<ll>(K, 1);
    for (int i = 1; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j < K; j++) sum += dp[i-1][j];
        for (int j = 0; j < K; j++) {
            dp[i][j] = sum - dp[i-1][j];
        }
    }
    ll ans = 0;
    for (int j = 0; j < K; j++) ans += dp[N-1][j];
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
