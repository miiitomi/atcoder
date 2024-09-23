// https://atcoder.jp/contests/abc153/tasks/abc153_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, N;
    cin >> H >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<ll> dp(H+1, INF);
    dp[H] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = H; j >= 0; j--) {
            dp[max(j-A[i], 0LL)] = min(dp[max(j-A[i], 0LL)], dp[j]+B[i]);
        }
    }
    cout << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
