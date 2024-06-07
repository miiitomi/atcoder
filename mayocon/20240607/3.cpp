// https://atcoder.jp/contests/abc242/tasks/abc242_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> dp(N, vector<ll>(10, 0));
    for (ll x = 1; x <= 9; x++) dp[0][x] = 1;

    for (int i = 0; i < N-1; i++) {
        for (int x = 1; x <= 9; x++) {
            for (int y = x-1; y <= x+1; y++) {
                if (!(1 <= y && y <= 9)) continue;
                dp[i+1][y] = (dp[i+1][y] + dp[i][x]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int x = 1; x <= 9; x++) ans = (ans + dp[N-1][x]) % MOD;
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
