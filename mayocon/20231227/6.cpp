// https://atcoder.jp/contests/abc236/tasks/abc236_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> A;

bool mean_can_larger_than_x (double x) {
    vector<double> B(N);
    for (int i = 0; i < N; i++) B[i] = A[i] - x;

    vector<vector<double>> dp(2, vector<double>(N, 0.0));
    dp[0][0] = 0.0;
    dp[1][0] = B[0];

    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + B[i];
    }

    return max(dp[0][N-1], dp[1][N-1]) >= 0.0;
}

bool med_can_larger_than_x(ll x) {
    vector<ll> B(N);
    for (int i = 0; i < N; i++) {
        if (A[i] >= x) B[i] = 1;
        else B[i] = -1;
    }

    vector<vector<ll>> dp(2, vector<ll>(N, 0));
    dp[0][0] = 0;
    dp[1][0] = B[0];

    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = max(dp[0][i-1], dp[1][i-1]) + B[i];
    }

    return max(dp[0][N-1], dp[1][N-1]) >= 1;
}


int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    double left = 0.0, right = 1.0 + (*max_element(A.begin(), A.end()));
    while (right - left > 1e-4) {
        double x = (right + left) / 2;
        if (mean_can_larger_than_x(x)) left = x;
        else right = x;
    }
    cout << fixed << setprecision(10) << left << "\n";

    ll l = 0, r = 1 + (*max_element(A.begin(), A.end()));
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (med_can_larger_than_x(m)) l = m;
        else r = m;
    }
    cout << l << "\n";
}
