// https://atcoder.jp/contests/abc211/tasks/abc211_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)(1e+9) + 7;
string chokudai = "chokudai";

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    int K = chokudai.size();
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int j = 0; j < K; j++) {
            if (S[i] == chokudai[j]) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }
    cout << dp.back().back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
