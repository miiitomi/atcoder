// https://atcoder.jp/contests/abc216/tasks/abc216_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> V(N);
    ll max_a = -1;
    for (int i = 0; i < N; i++) {
        cin >> V[i].first;
        max_a = max(max_a, V[i].first);
    }
    for (int i = 0; i < N; i++) cin >> V[i].second;
    sort(V.begin(), V.end());
    vector<vector<ll>> dp(N+1, vector<ll>(max_a+1, 0));
    dp[0][0] = 1;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a = V[i].first, b = V[i].second;
        dp[i+1] = dp[i];
        for (ll w = 0; w + b <= max_a; w++) {
            if (w+b <= a) ans = (ans + dp[i][w]) % MOD;
            dp[i+1][w+b] = (dp[i+1][w+b] + dp[i][w]) % MOD;
        }
    }
    cout << ans << endl;
}
