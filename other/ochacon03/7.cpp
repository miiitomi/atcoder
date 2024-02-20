#include <bits/stdc++.h>
using namespace std;
const int B = 1e+4;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    while (M--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }
    vector<bitset<B>> dp(N);
    for (int u = N-1; u >= 0; u--) {
        for (int v : G[u]) dp[u] |= dp[v];
        dp[u][u] = 1;
    }
    for (int u = 0; u < N; u++) {
        cout << dp[u].count()-1 << "\n";
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
