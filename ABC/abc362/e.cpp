#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<vector<map<ll, mint>>> dp(N, vector<map<ll, mint>>(N+1));
    vector<mint> ans(N+1, 0);
    ans[1] = N;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            ll r = A[j] - A[i];
            dp[j][2][r] += 1;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int k = 2; k <= N; k++) {
            for (auto iter = dp[i][k].begin(); iter != dp[i][k].end(); iter++) {
                ans[k] += iter->second;
                ll r = iter->first;
                for (int j = i+1; j < N; j++) {
                    if (A[j] == A[i]+r) {
                        dp[j][k+1][r] += iter->second;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= N; k++) {
        cout << ans[k].val() << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
