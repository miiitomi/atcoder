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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> dp(N+1, {-INF, -INF});
    dp[0] = {0, -INF};
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        dp[i+1][0] = max(dp[i+1][0], dp[i][1] + 2 * A[i]); 
        dp[i+1][1] = max(dp[i+1][1], dp[i][0] + A[i]);
    }
    cout << max(dp.back()[0], dp.back()[1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
