// https://atcoder.jp/contests/abc261/tasks/abc261_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> X(N);
    unordered_map<ll, ll> mp;
    for (int i = 0; i < N; i++) cin >> X[i];
    for (int i = 0; i < M; i++) {
        ll c, y;
        cin >> c >> y;
        mp[c] = y;
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == -1) continue;
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]);

            if (mp.count(j+1)) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + X[i] + mp[j+1]);
            else dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + X[i]);
        }
    }

    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}
