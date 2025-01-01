// https://atcoder.jp/contests/abc230/tasks/abc230_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, sum = 0;
    cin >> N;
    vector<ll> A(N), f(N+1, 0);
    map<ll,ll> mp;
    for (int i = 0; i < N; i++) {
        if (mp.contains(sum)) f[i+1] = mp[sum];
        mp[sum] = i;
        cin >> A[i];
        sum += A[i];
    }
    vector<mint> dp(N+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 2*dp[i-1] - dp[f[i]];
    }
    cout << dp.back().val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
