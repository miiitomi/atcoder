// https://atcoder.jp/contests/abc174/tasks/abc174_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K;
    cin >> K;
    vector<ll> dp(K, 1e+9);
    ll x = 7;
    for (ll t = 1; t <= K; t++) {
        dp[x % K] = min(dp[x % K], t);
        x = (10 * x + 7) % K;
    }

    if (dp[0] < 1e+9) cout << dp[0] <<endl;
    else cout << -1 << endl;
}
