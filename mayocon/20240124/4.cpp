// https://atcoder.jp/contests/abc322/tasks/abc322_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K));
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < K; j++) cin >> A[i][j];
    }

    vector<map<vector<int>,ll>> dp(N+1);
    dp[0][vector<int>(K, 0)] = 0;
    for (int i = 0; i < N; i++) {
        for (auto iter = dp[i].begin(); iter != dp[i].end(); iter++) {
            vector<int> v = iter->first;
            ll c = iter->second;
            if (!dp[i+1].count(v)) dp[i+1][v] = c;
            else dp[i+1][v] = min(dp[i+1][v], c);
            for (int s = 0; s < K; s++) v[s] = min(P, v[s] + A[i][s]);
            c += C[i];
            if (!dp[i+1].count(v)) dp[i+1][v] = c;
            else dp[i+1][v] = min(dp[i+1][v], c);
        }
    }

    ll ans = 9e+18;
    for (auto iter = dp[N].begin(); iter != dp[N].end(); iter++) {
        bool is_ok = true;
        for (int j = 0; j < K; j++) if (iter->first[j] < P) is_ok = false;
        if (is_ok) ans = min(ans, iter->second);
    }

    if (ans == 9e+18) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
