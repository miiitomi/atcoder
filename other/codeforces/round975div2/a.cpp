#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+9;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<pair<int,int>>> dp(N+1, vector<pair<int,int>>(N+1, {-INF, -INF}));
    dp[0][0] = {0, -INF};
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= N; k++) {
            dp[i+1][k].first = max(dp[i][k].first, dp[i][k].second);
            if (k < N && dp[i][k].first >= 0) dp[i+1][k+1].second = max(dp[i][k].first, A[i]);
        }
    }
    int ans = -INF;
    for (int i = 0; i <= N; i++) {
        for (int k = 0; k <= N; k++) {
            ans = max(ans, max(dp[i][k].first, dp[i][k].second) + k);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
