// https://atcoder.jp/contests/abc275/tasks/abc275_f
#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e+9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<pair<int, int>>> dp(N, vector<pair<int,int>>(M+1, make_pair(INF, INF))); // first:消す, second:残す
    for (int i = 0; i < N; i++) dp[i][0].first = 1;
    if (a[0] <= M) dp[0][a[0]].second = 0;
    for (int i = 1; i < N; i++) {
        int t = a[i];
        for (int x = 0; x <= M; x++) {
            dp[i][x].first = min(dp[i][x].first, dp[i-1][x].first);
            dp[i][x].first = min(dp[i][x].first, dp[i-1][x].second + 1);
            if (x + t > M) continue;
            dp[i][x + t].second = min(dp[i][x + t].second, dp[i-1][x].first);
            dp[i][x + t].second = min(dp[i][x + t].second, dp[i-1][x].second);
        }
    }

    for (int x = 1; x <= M; x++) {
        if (min(dp[N-1][x].first, dp[N-1][x].second) == INF) cout << -1 << endl;
        else cout << min(dp[N-1][x].first, dp[N-1][x].second) << endl;
    }
}
