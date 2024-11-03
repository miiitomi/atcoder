// https://atcoder.jp/contests/abc154/tasks/abc154_e
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
    int K;
    cin >> S >> K;
    ll N = S.size();
    vector<pair<ll,ll>> dp(K+1, make_pair(0LL, 0LL));
    dp[0].first = 1;
    for (char c = '1'; c <= '9'; c++) {
        if (c < S[0]) dp[1].first++;
        else if (c == S[0]) dp[1].second++;
    }
    for (int i = 1; i < N; i++) {
        vector<pair<ll,ll>> ndp(K+1, make_pair(0LL, 0LL));
        for (int k = 0; k <= K; k++) {
            ndp[k].first += dp[k].first;
            if (S[i] == '0') ndp[k].second += dp[k].second;
            else ndp[k].first += dp[k].second;
            if (k == K) continue;
            for (char c = '1'; c <= '9'; c++) {
                if (c < S[i]) {
                    ndp[k+1].first += dp[k].first + dp[k].second;
                } else if (c == S[i]){
                    ndp[k+1].first += dp[k].first;
                    ndp[k+1].second += dp[k].second;
                } else {
                    ndp[k+1].first += dp[k].first;
                }
            }
        }
        swap(dp, ndp);
    }
    ll ans = dp[K].first + dp[K].second;
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
