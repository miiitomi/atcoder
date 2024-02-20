#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> dp(1 << N, 0);
    dp[0] = 1;

    for (int i = 0; i < D; i++) {
        vector<ll> ndp = dp;
        for (int s = 0; s < (1 << N); s++) {
            if (dp[s] == 0) continue;
            int t = s;
            for (int j = 0; j < N; j++) {
                if (A[j] & (1LL << i)) t = t | (1 << j);
            }
            ndp[t] += dp[s];
        }
        swap(dp, ndp);
    }
    cout << dp[(1 << N) - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
