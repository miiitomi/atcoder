// https://atcoder.jp/contests/abc149/tasks/abc149_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    ll n = N/K, r = N%K;
    ll ans = 0;
    for (int k = 0; k < K; k++) {
        ll m = n + (k <= (r-1));
        vector<vector<ll>> dp(m, vector<ll>(3, 0));
        if (T[k] == 'r') dp[0][2] = P;
        else if (T[k] == 's') dp[0][0] = R;
        else dp[0][1] = S;
        for (int i = 1; k+K*i < N; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + (T[k+K*i] == 's')*R;
            dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + (T[k+K*i] == 'p')*S;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + (T[k+K*i] == 'r')*P;
        }
        ans += *max_element(dp.back().begin(), dp.back().end());
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
