// https://atcoder.jp/contests/abc187/tasks/abc187_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, M;
vector<vector<bool>> G;

void solve() {
    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    vector<int> dp(1 << N, 1);
    for (int s = 1; s < (1 << N); s++) {
        vector<int> v;
        for (int i = 0; i < N; i++) if (s & (1 << i)) v.push_back(i);
        dp[s] = v.size();
        bool is_ok = true;
        for (int i = 1; i < (int)v.size(); i++) {
            if (!G[v[0]][v[i]]) {
                is_ok = false;
                break;
            }
        }
        if (is_ok && dp[s - (1 << v[0])]==1) {
            dp[s] = 1;
        } else {
            for (int t = s-1; t > 0; t = s & (t-1)) {
                dp[s] = min(dp[s], dp[t] + dp[s-t]);
            }
        }
    }
    cout << dp.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
