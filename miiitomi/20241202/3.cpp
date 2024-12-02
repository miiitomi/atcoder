// https://atcoder.jp/contests/abc272/tasks/abc272_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dp(N, vector<int>(N, -1));
    dp[0][0] = 0;
    queue<pair<int,int>> Q;
    Q.push({0, 0});
    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        for (int k = 0; k < N; k++) {
            int t = M - (i-k)*(i-k);
            if (t < 0) continue;
            int left = 0, right = 401;
            while (right - left > 1) {
                int m = (left + right) / 2;
                if (m*m <= t) left = m;
                else right = m;
            }
            if (left * left != t) continue;

            int l = j + left;
            if (l < N && dp[k][l] == -1) {
                dp[k][l] = dp[i][j] + 1;
                Q.push({k, l});
            }
            l = j - left;
            if (l >= 0 && dp[k][l] == -1) {
                dp[k][l] = dp[i][j] + 1;
                Q.push({k, l});                
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << dp[i][j];
            if (j == N-1) cout << "\n";
            else cout << " ";
        }
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
