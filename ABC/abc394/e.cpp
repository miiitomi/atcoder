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
    vector<string> S(N), T(N, string(N, '-'));
    for (string &s : S) cin >> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] != '-') T[j][i] = S[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, -1));
    queue<pair<int,int>> Q;
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
        Q.push({i, i});
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (S[i][j] != '-') {
                dp[i][j] = 1;
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()) {
        auto [i, j] = Q.front();
        Q.pop();
        for (int k = 0; k < N; k++) {
            if (T[i][k] == '-') continue;
            for (int l = 0; l < N; l++) {
                if (T[i][k] == S[j][l] && dp[k][l] == -1) {
                    dp[k][l] = dp[i][j] + 2;
                    Q.push({k, l});
                }
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
