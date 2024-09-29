#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    mint tmp = 1;
    vector<mint> dp(N+1, 0);
    dp[0] = 1;
    map<ll, mint> mp;
    mp[0] = 1;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        dp[i+1] = tmp - mp[sum - K];
        tmp += dp[i+1];
        mp[sum] += dp[i+1];
    }
    cout << dp.back().val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
