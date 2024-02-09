#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>((int)1e+5 + 2, 0));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= (int)1e+5; j++) dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
        if (i == N-1) break;

        int B = 1e+5 - A[i+1];

        for (int j = 0; j <= (int)1e+5; j++) {
            int x = max((ll)j, A[i] + j - A[i+1]);
            if (x <= B) {
                dp[i+1][x] = (dp[i+1][x] + dp[i][j]) % MOD;
                dp[i+1][B+1] = (dp[i+1][B+1] - dp[i][j] + MOD) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= (int)1e+5; j++) ans = (ans + dp[N-1][j]) % MOD;
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
