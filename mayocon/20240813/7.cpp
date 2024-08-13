// https://atcoder.jp/contests/abc163/tasks/abc163_e
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
    vector<pair<ll,ll>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -INF));
    dp[0][0] = 0;
    for (int k = 0; k < N; k++) {
        ll a = A[k].first, i = A[k].second;
        for (int x = 0; x <= k; x++) {
            int y = k - x;
            dp[x+1][y] = max(dp[x+1][y], dp[x][y] + a*(i - x));
            dp[x][y+1] = max(dp[x][y+1], dp[x][y] + a*(N-1-y - i));
        }
    }
    ll ans = -INF;
    for (ll x = 0; x <= N; x++) {
        ans = max(ans, dp[x][N-x]);
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
