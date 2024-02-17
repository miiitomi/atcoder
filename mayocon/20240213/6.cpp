// https://atcoder.jp/contests/abc207/tasks/abc207_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    vector<vector<mint>> memo(N+2, vector<mint>(N+1, 0));
    dp[0][0] = 1;
    memo[1][0] = 1;
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i-1];
        for (int j = 1; j <= i; j++) dp[i][j] += memo[j][sum % j];
        for (int j = 1; j <= i; j++) memo[j+1][sum % (j+1)] += dp[i][j];
    }
    mint ans = 0;
    for (int j = 1; j <= N; j++) ans += dp.back()[j];
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
