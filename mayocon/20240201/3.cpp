// https://atcoder.jp/contests/abc220/tasks/abc220_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<ll>> dp(N, vector<ll>(10, 0));
    dp[0][A[0]] = 1;

    for (int i = 1; i <= N-1; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[i-1][j] == 0) continue;
            int f = (j + A[i]) % 10, g = (j * A[i]) % 10;
            dp[i][f] = (dp[i][f] + dp[i-1][j]) % MOD;
            dp[i][g] = (dp[i][g] + dp[i-1][j]) % MOD;
        }
    }
    for (int k = 0; k < 10; k++) {
        cout << dp[N-1][k] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
