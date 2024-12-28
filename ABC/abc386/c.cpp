#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1e+9;
const ll MOD = 998244353;

void solve() {
    ll K;
    string S, T;
    cin >> K >> S >> T;
    vector<vector<int>> dp(S.size()+1, vector<int>(2*K+1, INF));
    dp[0][K] = 0;
    for (int i = 0; i <= (int)S.size(); i++) {
        for (int k = 0; k <= 2*K; k++) {
            if (dp[i][k] == INF) continue;
            int j = i + k - K;
            if (i < (int)S.size() && j < (int)T.size() && S[i]==T[j]) dp[i+1][k] = min(dp[i+1][k], dp[i][k]);
            if (i < (int)S.size()) dp[i+1][k] = min(dp[i+1][k], dp[i][k]+1);
            if (i < (int)S.size() && k >= 1) dp[i+1][k-1] = min(dp[i+1][k-1], dp[i][k]+1);
            if (k < 2*K) dp[i][k+1] = min(dp[i][k+1], dp[i][k]+1);
        }
    }
    for (int k = 0; k <= 2*K; k++) {
        int j = S.size() + k - K;
        if (j == (int)T.size() && dp.back()[k] <= K) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
