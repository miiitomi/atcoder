// https://atcoder.jp/contests/abc225/tasks/abc225_f
#include <bits/stdc++.h>
using namespace std;

bool cmp(string &l, string &r) {
    return l+r < r+l;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end(), cmp);
    vector<vector<string>> dp(N+1, vector<string>(K+1, string(50*50+1, 'z')));
    dp[N][0] = "";
    for (int i = N-1; i >= 0; i--) {
        for (int k = 0; k <= K; k++) {
            dp[i][k] = min(dp[i][k], dp[i+1][k]);
            if (k+1 <= K) dp[i][k+1] = min(dp[i][k+1], S[i] + dp[i+1][k]);
        }
    }
    cout << dp[0][K] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
