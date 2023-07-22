#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    set<pair<int, int>> S;
    for (int i = 0; i < N; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
        S.insert(p);
    }

    ll ans = 0;
    vector<vector<int>> dp(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S.count(make_pair(i, j))) continue;
            int x = 1e+9;
            if (i != 0) x = min(x, dp[i-1][j]);
            else x = 0;
            if (j != 0) x = min(x, dp[i][j-1]);
            else x = 0;
            if (i != 0 && j != 0) x = min(x, dp[i-1][j-1]);
            dp[i][j] = x + 1;
            ans += dp[i][j];
        }
    }

    cout << ans << endl;
}
