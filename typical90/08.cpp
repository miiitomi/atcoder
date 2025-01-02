// https://atcoder.jp/contests/typical90/tasks/typical90_h
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    string a = "atcoder";
    vector<vector<mint>> dp(N+1, vector<mint>(a.size()+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        dp[i+1] = dp[i];
        for (int k = 0; k < (int)a.size(); k++) {
            if (S[i] != a[k]) continue;
            dp[i+1][k+1] += dp[i][k];
        }
    }
    cout << dp.back().back().val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
