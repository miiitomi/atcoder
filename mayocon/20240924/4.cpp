// https://atcoder.jp/contests/abc312/tasks/abc312_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    ll N = S.size();
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));    
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            if (S[i] != ')' && j != N) dp[i+1][j+1] += dp[i][j];
            if (S[i] != '(' && j != 0) dp[i+1][j-1] += dp[i][j];
        }
    }
    cout << dp.back()[0].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
