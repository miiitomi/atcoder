#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using namespace atcoder;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    scc_graph g(N);
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        g.add_edge(i, a[i]);
    }

    vector<vector<int>> scc = g.scc();
    reverse(scc.begin(), scc.end());
    vector<ll> dp(N, -1), group(N, -1);
    ll ans = 0;
    for (vector<int> &V : scc) {
        for (int &u : V) group[u] = V[0];
        for (int &u : V) {
            if (group[u] == group[a[u]]) dp[u] = V.size();
            else dp[u] = 1 + dp[a[u]];
            ans += dp[u];
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
