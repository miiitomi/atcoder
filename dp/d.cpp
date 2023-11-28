#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j < W; j++) {
            if (j + w[i] <= W) {
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}
