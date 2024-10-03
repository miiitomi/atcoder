// https://atcoder.jp/contests/abc326/tasks/abc326_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N+1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<mint> dp(N+1, 0);
    dp[N] = A[N];
    mint sum = 0, p = ((mint)N).inv();
    for (int i = N; i >= 0; i--) {
        dp[i] = A[i] + sum * p;
        sum += dp[i];
    }
    cout << dp.front().val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
