// https://atcoder.jp/contests/abc364/tasks/abc364_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<vector<ll>> dp(N+1, vector<ll>(X+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<vector<ll>> ndp = dp;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= X; k++) {
                if (dp[j][k] == INF) continue;
                if (k + A[i] <= X) {
                    ndp[j+1][k+A[i]] = min(dp[j][k]+B[i], ndp[j+1][k+A[i]]);
                }
            }
        }
        swap(dp, ndp);
    }
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int x = 0; x <= X; x++) {
            if (dp[i][x] <= Y) ans = i;
        }
    }
    if (ans < N) ans++;
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
