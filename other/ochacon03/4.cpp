#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < N; j++) cin >> B[j];

    if (N <= 2) {
        ll ans = 0;
        for (int k = 0; k < N; k++) ans += A[k] - B[k];
        cout << ans << "\n";
        return;
    }

    vector<vector<ll>> dp(N-1, vector<ll>(N-1, INF));
    dp[0][0] = A[0] - B[0];
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < N-1; j++) {
            if (i+1 < N-1) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + K);
            if (j+1 < N-1) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + K);
            if (i+1 < N-1 && j+1 < N-1) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + A[i+1] - B[j+1]);
        }
    }
    cout << dp.back().back() + A.back() - B.back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
