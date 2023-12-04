#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, S, M, L;
    cin >> N >> S >> M >> L;

    vector<ll> dp(N+13, 1e+8);
    dp[0] = 0;
    for (int x = 0; x <= N+12; x++) {
        if (x+6 <= N+12) dp[x + 6] = min(dp[x + 6], dp[x] + S);
        if (x+8 <= N+12) dp[x + 8] = min(dp[x + 8], dp[x] + M);
        if (x+12 <= N+12) dp[x + 12] = min(dp[x + 12], dp[x] + L);
    }
    ll ans = 1e+8;
    for (int x = N; x <= N+12; x++) {
        ans = min(ans, dp[x]);
    }
    cout << ans << endl;
}
