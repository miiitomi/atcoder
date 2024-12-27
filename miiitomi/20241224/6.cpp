// https://atcoder.jp/contests/abc208/tasks/abc208_e
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
    ll K;
    cin >> S >> K;
    reverse(S.begin(), S.end());
    ll M = S.size();
    vector<vector<map<ll,ll>>> dp(M, vector<map<ll,ll>>(2));
    for (char c = '1'; c <= S[M-1]; c++) {
        if (c < S[M-1]) dp[M-1][0][(ll)(c - '0')] = 1;
        else dp[M-1][1][(ll)(c - '0')] = 1;
    }
    for (int i = M-2; i >= 0; i--) {
        for (char c = '0'; c <= '9'; c++) {
            for (int k = 0; k < 2; k++) {
                if (k == 1 && c > S[i]) continue;
                for (auto iter = dp[i+1][k].begin(); iter != dp[i+1][k].end(); iter++) {
                    ll s = iter->first, t = iter->second;
                    dp[i][(k==1)&&(c==S[i])][min(s*(ll)(c - '0'), K+1)] += t;
                }
            }
            if (c != '0') dp[i][0][c-'0'] += 1;
        }
    }
    ll ans = 0;
    for (int k = 0; k < 2; k++) {
        for (auto iter = dp[0][k].begin(); iter != dp[0][k].end(); iter++) {
            if (iter->first <= K) ans += iter->second;
        }
    }
    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
