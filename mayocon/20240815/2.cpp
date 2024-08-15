// https://atcoder.jp/contests/abc209/tasks/abc209_c
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
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());
    vector<mint> dp(N);
    dp[0] = C[0];
    for (int i = 1; i < N; i++) {
        if (C[i] > i) dp[i] = dp[i-1] * (C[i] - i);
        else dp[i] = 0;
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
