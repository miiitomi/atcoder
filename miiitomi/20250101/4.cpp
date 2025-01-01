// https://atcoder.jp/contests/abc044/tasks/arc060_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A;
    cin >> N >> A;
    vector<ll> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(A*N + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int k = 0; k < N; k++) {
            for (int a = 0; a+x[i] <= A*N; a++) {
                dp[i+1][k+1][a+x[i]] += dp[i][k][a];
            }
        }
    }
    ll ans = 0;
    for (int k = 1; k <= N; k++) ans += dp[N][k][k*A];
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
