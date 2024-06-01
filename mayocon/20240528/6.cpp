// https://atcoder.jp/contests/abc236/tasks/abc236_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
vector<ll> A;

void mean() {
    double l = 0.0, r = 2e+9;
    for (int k = 0; k < 100; k++) {
        double m = (l + r) / 2.0;
        vector<vector<double>> dp(N+1, vector<double>(2, -2e+9));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 0; i < N; i++) {
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = max(dp[i][0], dp[i][1]) + A[i]-m;
        }
        if (max(dp.back()[0], dp.back()[1]) >= 0.0) l = m;
        else r = m;
    }
    cout << l << endl;
}

void median() {
    ll l = 0, r = 2e+9;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
        for (int i = 0; i < N; i++) {
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = max(dp[i][0], dp[i][1]) + (2*(int)(A[i] >= m) - 1);
        }
        if (max(dp.back()[0], dp.back()[1]) > 0) l = m;
        else r = m;
    }
    cout << l << endl;
}


void solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    mean();
    median();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
