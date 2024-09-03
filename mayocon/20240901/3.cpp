// https://atcoder.jp/contests/abc291/tasks/abc291_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<vector<mint>> dp(N, {0, 0});
    dp[0] = {1, 1};
    for (int i = 0; i < N-1; i++) {
        if (A[i] != A[i+1]) dp[i+1][0] += dp[i][0];
        if (A[i] != B[i+1]) dp[i+1][1] += dp[i][0];
        if (B[i] != A[i+1]) dp[i+1][0] += dp[i][1];
        if (B[i] != B[i+1]) dp[i+1][1] += dp[i][1];
    }
    mint ans = dp.back()[0] + dp.back()[1];
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
