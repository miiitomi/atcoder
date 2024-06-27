// https://atcoder.jp/contests/abc271/tasks/abc271_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M), B(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }
    vector<ll> dp(N, INF);
    dp[0] = 0;
    while (K--) {
        ll e;
        cin >> e;
        e--;
        dp[B[e]] = min(dp[B[e]], dp[A[e]] + C[e]);
    }
    ll ans = dp[N-1];
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
