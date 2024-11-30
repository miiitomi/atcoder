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
    cin >> N;
    vector<vector<int>> B(20);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        B[a].push_back(i);
    }
    vector<ll> dp(1 << 20, INF);
    dp[0] = 0;
    for (int s = 0; s < (1 << 20); s++) {
        if (dp[s] == INF) continue;
        for (int a = 0; a < 20; a++) {
            if (s & (1 << a)) continue;
            int i = distance(B[a].begin(), lower_bound(B[a].begin(), B[a].end(), dp[s]));
            if (i+1 < (int)B[a].size()) {
                dp[s ^ (1 << a)] = min(dp[s ^ (1 << a)], B[a][i+1]+1LL);
            }
        }
    }
    int ans = 0;
    for (int s = 0; s < (1 << 20); s++) {
        if (dp[s] == INF) continue;
        int cnt = 0;
        for (int a = 0; a < 20; a++) {
            if (s & (1 << a)) cnt++;
        }
        ans = max(ans, 2*cnt);
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
