// https://atcoder.jp/contests/abc259/tasks/abc259_h
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
vector<mint> F(1000, 1);
vector<vector<mint>> C(1000, vector<mint>(1000, 1));

void solve() {
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> B(N*N);
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j]--;
            B[a[i][j]].push_back({i, j});
        }
    }

    mint ans = 0;
    for (int x = 0; x < N*N; x++) {
        if ((int)B[x].size() <= N) {
            for (auto p : B[x]) {
                for (auto q : B[x]) {
                    if (p.first > q.first || p.second > q.second) continue;
                    ans += C[q.first-p.first+q.second-p.second][q.first-p.first];
                }
            }
        } else {
            vector<vector<mint>> dp(N, vector<mint>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (a[i][j] == x) {
                        dp[i][j]++;
                        ans += dp[i][j];
                    }
                    if (i+1 < N) dp[i+1][j] += dp[i][j];
                    if (j+1 < N) dp[i][j+1] += dp[i][j];
                }
            }
        }
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 1000; x++) F[x] = x * F[x-1];
    for (int n = 0; n < 1000; n++) {
        for (int r = 0; r <= n; r++) {
            C[n][r] = F[n]/(F[n-r]*F[r]);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
