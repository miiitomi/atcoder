// https://atcoder.jp/contests/abc201/tasks/abc201_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];

    vector<vector<pair<int,int>>> dp(H, vector<pair<int,int>>(W, make_pair(0, 0)));
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (i == H-1 && j == W-1) {
                continue;
            } else if (i == H-1) {
                dp[i][j] = make_pair((A[i][j+1] == '+')*1 + (A[i][j+1] == '-')*(-1) + + dp[i][j+1].second, dp[i][j+1].first);
            } else if (j == W-1) {
                dp[i][j] = make_pair((A[i+1][j] == '+')*1 + (A[i+1][j] == '-')*(-1) + dp[i+1][j].second, dp[i+1][j].first);
            } else {
                int a = (A[i+1][j] == '+')*1 + (A[i+1][j] == '-')*(-1) + dp[i+1][j].second - dp[i+1][j].first;
                int b = (A[i][j+1] == '+')*1 + (A[i][j+1] == '-')*(-1) + dp[i][j+1].second - dp[i][j+1].first;
                if (a > b) dp[i][j] = make_pair((A[i+1][j] == '+')*1 + (A[i+1][j] == '-')*(-1) + dp[i+1][j].second,  dp[i+1][j].first);
                else dp[i][j] = make_pair((A[i][j+1] == '+')*1 + (A[i][j+1] == '-')*(-1) + dp[i][j+1].second, dp[i][j+1].first);
            }
        }
    }

    if (dp[0][0].first > dp[0][0].second) cout << "Takahashi" << endl;
    else if (dp[0][0].first < dp[0][0].second) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}
