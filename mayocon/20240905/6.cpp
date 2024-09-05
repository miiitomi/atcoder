// https://atcoder.jp/contests/abc207/tasks/abc207_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0;
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0)), memo(N+1, vector<mint>(N+1, 0));
    dp[0][0] = 1;
    memo[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        sum += A[i-1];
        for (int k = 1; k <= i; k++) dp[i][k] += memo[k-1][sum % k];
        for (int k = 1; k <= i; k++) memo[k][sum % (k+1)] += dp[i][k];
    }
    mint ans = 0;
    for (int k = 1; k <= N; k++) ans += dp[N][k];
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
