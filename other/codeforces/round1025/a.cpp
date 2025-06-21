#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) cin >> a;

    vector<vector<bool>> dp(N, vector<bool>(2, false));
    dp[0] = {true, false};

    for (int i = 0; i < N-1; i++) {
        if (dp[i][0]) {
            if (A[i] == 0) {
                if (A[i+1]) {
                    dp[i+1][1] = true;
                }
            } else {
                dp[i+1][0] = true;
            }
        }
        if (dp[i][1]) {
            dp[i+1][0] = true;
            if (A[i+1] == 1) dp[i+1][1] = true;
        }

        if (!dp[i+1][0] && !dp[i+1][1]) {
            cout << "YES\n";
            return;
        }
    }

    if (A.back() == 0) dp.back()[1] = false;
    if (A.back() == 1) dp.back()[0] = false;

    if (!dp.back()[0] && !dp.back()[1]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
