// https://atcoder.jp/contests/abc216/tasks/abc216_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), v(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), [&](const int i, const int j) {return A[i] < A[j];});
    vector<ll> dp(5001, 0);
    dp[0] = 1;
    ll ans = 0;
    for (int i : v) {
        for (int x = 5000; x >= 0; x--) {
            if (x + B[i] <= A[i]) ans = (ans + dp[x]) % MOD;
            if (x + B[i] <= 5000) dp[x+B[i]] = (dp[x+B[i]] + dp[x]) % MOD;
        }
    }
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
