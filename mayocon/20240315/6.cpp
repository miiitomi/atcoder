// https://atcoder.jp/contests/abc232/tasks/abc232_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL << 62);

void chmin(ll &target, ll value) {
    if (target > value) target = value;
}

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    vector<vector<ll>> dp(N+1, vector<ll>((1 << N), INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int s = 0; s < (1 << N); s++) {
            if (dp[i][s] == INF) continue;
            ll cnt = 0, tmp = dp[i][s];
            for (int j = 0; j < N; j++) {
                if (s & (1 << j)) continue;
                chmin(dp[i+1][s + (1 << j)], tmp + cnt*Y + abs(B[i] - A[j]) * X);
                cnt++;
            }
        }
    }
    cout << dp.back().back() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
