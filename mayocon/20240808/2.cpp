// https://atcoder.jp/contests/abc214/tasks/abc214_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin  >> N;
    vector<ll> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];
    int i = distance(T.begin(), min_element(T.begin(), T.end()));
    vector<ll> dp(N, INF);
    for (int k = 0; k < N; k++) {
        dp[i] = min(dp[i], T[i]);
        dp[(i+1)%N] = min(dp[(i+1)%N], dp[i] + S[i]);
        i = (i+1)%N;
    }

    for (int i = 0; i < N; i++) {
        cout << dp[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
