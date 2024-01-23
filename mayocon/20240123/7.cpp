// https://atcoder.jp/contests/abc144/tasks/abc144_f
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        G[s].push_back(t);
    }

    vector<double> dp(N, 0);
    for (int i = N-2; i >= 0; i--) {
        double p = 1.0 / G[i].size();
        for (int v : G[i]) dp[i] += p*(1 + dp[v]);
    }
    double ans = dp[0];
    for (int i = 0; i <= N-2; i++) {
        if (G[i].size() == 1) continue;
        double p = 1.0 / (G[i].size() - 1), new_dpi = 1e+18;
        for (int u : G[i]) {
            double tmp = 0;
            for (int v : G[i]) if (u != v) tmp += p*(1 + dp[v]);
            new_dpi = min(new_dpi, tmp);
        }
        vector<double> ndp = dp;
        ndp[i] = new_dpi;
        for (int j = i-1; j >= 0; j--) {
            ndp[j] = 0;
            double q = 1.0 / G[j].size();
            for (int u : G[j]) ndp[j] += q * (1 + ndp[u]);
        }
        ans = min(ans, ndp[0]);
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
