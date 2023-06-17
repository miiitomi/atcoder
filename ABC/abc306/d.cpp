#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        if (x == 0) {
            dp[i+1][0] = max(dp[i][0], dp[i][0] + y);
            dp[i+1][0] = max(dp[i+1][0], dp[i][1] + y);
            dp[i+1][1] = dp[i][1];
        } else {
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = max(dp[i][1], dp[i][0] + y);
        }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;
}
