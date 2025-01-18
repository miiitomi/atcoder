// https://atcoder.jp/contests/abc197/tasks/abc197_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<vector<ll>>> G(26, vector<vector<ll>>(N));
    vector<vector<bool>> H(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        H[a][b] = true;
        H[b][a] = true;
        G[c-'a'][a].push_back(b);
        G[c-'a'][b].push_back(a);
    }
    vector<vector<ll>> dp(N, vector<ll>(N, -1));
    dp[0][N-1] = 0;
    queue<pair<ll,ll>> Q;
    Q.push({0, N-1});
    while (!Q.empty()) {
        auto [u, v] = Q.front();
        Q.pop();

        if (H[u][v]) {
            cout << 2*dp[u][v] + 1 << "\n";
            return;
        }

        for (char c = 0; c < 26; c++) {
            for (int s : G[c][u]) {
                for (int t : G[c][v]) {
                    if (s == t) {
                        cout << 2*dp[u][v] + 2 << "\n";
                        return;
                    }
                    if (dp[s][t] != -1) continue;
                    dp[s][t] = dp[u][v] + 1;
                    Q.push({s, t});
                }
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
