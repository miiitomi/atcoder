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
    string S;
    cin >> N >> S;
    vector<vector<ll>> dp(N+1, vector<ll>(3, -INF));
    dp[0] = {0, 0, 0};
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            dp[i+1][0] = max(dp[i][1], dp[i][2]);
            dp[i+1][1] = -INF;
            dp[i+1][2] = max(dp[i][0], dp[i][1]) + 1;
        } else if (S[i] == 'S') {
            dp[i+1][0] = max(dp[i][1], dp[i][2]) + 1;
            dp[i+1][1] = max(dp[i][0], dp[i][2]);
            dp[i+1][2] = -INF;
        } else {
            dp[i+1][0] = -INF;
            dp[i+1][1] = max(dp[i][0], dp[i][2]) + 1;
            dp[i+1][2] = max(dp[i][0], dp[i][1]);
        }
    }

    ll ans = *max_element(dp[N].begin(), dp[N].end());
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
