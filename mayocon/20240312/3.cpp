// https://atcoder.jp/contests/abc242/tasks/abc242_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> dp(N, vector<ll>(10, 0));
    for (int j = 1; j <= 9; j++) dp[0][j] = 1;
    for (int i = 0; i < N-1; i++) {
        for (int j = 1; j <= 9; j++) {
            ll a = dp[i][j];
            for (int k = 1; k <= 9; k++) {
                if (abs(j - k) >= 2) continue;
                dp[i+1][k] = (dp[i+1][k] + a) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= 9; j++) ans = (ans + dp.back()[j]) % MOD;
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
