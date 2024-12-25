// https://atcoder.jp/contests/abc052/tasks/arc067_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    for (ll &x : X) cin >> x;
    vector<ll> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N-1; i++) {
        dp[i+1] = dp[i] + min(A*(X[i+1]-X[i]), B);
    }
    cout << dp.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
