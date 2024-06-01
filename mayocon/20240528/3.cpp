// https://atcoder.jp/contests/abc220/tasks/abc220_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>(10, 0));
    dp[0][A.front()]++;
    for (int i = 1; i < N; i++) {
        int y = A[i];
        for (int x = 0; x < 10; x++) {
            dp[i][(x + y) % 10] = (dp[i][(x + y) % 10] + dp[i-1][x]) % MOD;
            dp[i][(x * y) % 10] = (dp[i][(x * y) % 10] + dp[i-1][x]) % MOD;
        }
    }
    for (int k = 0; k < 10; k++) cout << dp[N-1][k] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
