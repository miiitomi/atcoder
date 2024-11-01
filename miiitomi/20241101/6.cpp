// https://atcoder.jp/contests/abc056/tasks/arc070_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<vector<bool>> dp1(N+1, vector<bool>(K, false)), dp2(N+1, vector<bool>(K, false));
    dp1[0][0] = true;
    for (int i = 0; i < N; i++) {
        dp1[i+1] = dp1[i];
        for (int k = 0; k < K; k++) if (dp1[i][k] && k+a[i] < K) dp1[i+1][k+a[i]] = true;
    }
    dp2[N][0] = true;
    for (int i = N-1; i >= 0; i--) {
        dp2[i] = dp2[i+1];
        for (int k = 0; k < K; k++) if (dp2[i+1][k] && k+a[i] < K) dp2[i][k+a[i]] = true;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool is_need = false;
        vector<int> s(K+1, 0);
        for (int k = 0; k < K; k++) {
            s[k+1] += s[k];
            if (dp2[i+1][k]) s[k+1]++;
        }
        for (int k = 0; k < K; k++) {
            if (!dp1[i][k]) continue;
            if (s[K-k]-s[max(K-k-a[i], 0)] >= 1) is_need = true;
        }
        if (!is_need) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
