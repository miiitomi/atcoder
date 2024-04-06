// https://atcoder.jp/contests/abc286/tasks/abc286_d
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

void solve() {
    int N, X;
    cin >> N >> X;
    vector<vector<int>> dp(N+1, vector<int>(X+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= X; j++) {
            if (dp[i][j] != INF) dp[i+1][j] = 0;
            else if (j >= a) {
                if (dp[i][j-a] != INF) dp[i+1][j] = 1;
                else if (dp[i+1][j-a] <= b-1) dp[i+1][j] = dp[i+1][j-a] + 1;
            }
        }
    }

    if (dp.back().back() != INF) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
