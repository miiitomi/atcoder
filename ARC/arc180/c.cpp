#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int MV = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        MV += abs(A[i]);
    }
    vector<vector<mint>> dp(N+1, vector<mint>(2*MV + 1, 0));
    dp[0][MV] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 2*MV; j++) {
            if (j-MV == A[i-1]) continue;
            int l = j - A[i-1];
            if (!(0 <= l && l <= 2*MV)) continue;

            for (int k = 0; k < i; k++) {
                if (k == 0 || A[k-1] != l-MV) dp[i][j] += dp[k][l];
                bool is_true = false;
                for (int m = k+1; m < i; m++) {
                    if (A[m-1] == j-A[i-1]-MV) is_true = true;
                }
                if (is_true) dp[i][j] += dp[k][MV];
            }
        }
    }

    mint ans = 0;
    for (auto &v : dp) {
        for (mint &x : v) {
            ans += x;
        }
    }
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
