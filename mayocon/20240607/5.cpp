// https://atcoder.jp/contests/abc117/tasks/abc117_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<pair<ll,ll>> dp(60, {-1, 0});
    for (ll k = 58; k >= 0; k--) {
        ll zero = 0, one = 0;
        for (ll a : A) {
            if (a & (1LL << k)) one++;
            else zero++;
        }

        if (dp[k+1].first >= 0) dp[k].first = dp[k+1].first + (1LL << k) * max(zero, one);
        if (K & (1LL << k)) {
            dp[k].first = max(dp[k].first, dp[k+1].second + (1LL << k) * one);
            dp[k].second = dp[k+1].second + (1LL << k) * zero;
        } else {
            dp[k].second = dp[k+1].second + (1LL << k) * one;
        }
    }

    cout << max(dp[0].first, dp[0].second) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
