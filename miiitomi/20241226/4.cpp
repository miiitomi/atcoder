// https://atcoder.jp/contests/abc197/tasks/abc197_e
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
    vector<vector<ll>> X(N+1);
    for (int i = 0; i < N; i++) {
        int x, c;
        cin >> x >> c;
        X[c].push_back(x);
    }
    ll left = 0, right = 0;
    vector<ll> dp(2, 0);
    for (int c = 1; c <= N; c++) {
        if (X[c].empty()) continue;
        sort(X[c].begin(), X[c].end());
        vector<ll> ndp(2, INF);
        ll mi = X[c].front(), ma = X[c].back();
        ndp[0] = min(dp[0] + abs(ma - left) + ma - mi, dp[1] + abs(ma - right) + ma - mi);
        ndp[1] = min(dp[0] + abs(mi - left) + ma - mi, dp[1] + abs(mi - right) + ma - mi);
        swap(dp, ndp);
        left = mi;
        right = ma;
    }
    ll ans = min(dp[0] + abs(left), dp[1] + abs(right));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
