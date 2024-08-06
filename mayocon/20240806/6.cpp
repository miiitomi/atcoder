// https://atcoder.jp/contests/abc236/tasks/abc236_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> A;

bool f(double x) {
    vector<double> dp(N+2, 0);
    for (int i = 0; i < N; i++) {
        dp[i+2] = max(dp[i], dp[i+1]) + A[i] - x;
    }
    if (max(dp[N+1], dp[N]) >= 0.0) return true;
    else return false;
}

bool g(ll x) {
    vector<ll> dp(N+2, 0);
    for (int i = 0; i < N; i++) {
        dp[i+2] = max(dp[i], dp[i+1]) + 1 - 2*(A[i] < x);
    }
    if (max(dp[N+1], dp[N]) > 0) return true;
    else return false;
}

void solve() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    double mi = (double)*min_element(A.begin(), A.end());
    double ma = (double)*max_element(A.begin(), A.end());
    for (int k = 0; k < 100; k++) {
        double m = (mi + ma)/2.0;
        if (f(m)) mi = m;
        else ma = m;
    }
    cout << mi << "\n";

    ll left = *min_element(A.begin(), A.end()) - 1;
    ll right = *max_element(A.begin(), A.end()) + 1;
    while (right - left > 1) {
        ll m = (left + right) / 2;
        if (g(m)) left = m;
        else right = m;
    }
    cout << left << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
