// https://atcoder.jp/contests/abc259/tasks/abc259_h
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

vector<mint> F(800, 1);
vector<vector<mint>> C(800, vector<mint>(800, 1));

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    vector<vector<pair<int, int>>> v(N*N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            a[i][j]--;
            v[a[i][j]].push_back(make_pair(i, j));
        }
    }
    mint ans = 0;
    for (int x = 0; x < N*N; x++) {
        if ((int)v[x].size() > N) {
            vector<vector<mint>> dp(N, vector<mint>(N, 0));
            for (pair<int,int> &p : v[x]) dp[p.first][p.second] = 1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (a[i][j] == x) ans += dp[i][j];
                    if (i+1 < N) dp[i+1][j] += dp[i][j];
                    if (j+1 < N) dp[i][j+1] += dp[i][j];
                }
            }
        } else {
            for (pair<int,int> &p : v[x]) {
                for (pair<int,int> &q : v[x]) {
                    if (p.first > q.first || p.second > q.second) continue;
                    ans += C[q.first - p.first + q.second - p.second][q.first - p.first];
                }
            }
        }
    }
    cout << ans.val() << "\n";
}

int main() {
    for (int x = 1; x < 800; x++) F[x] = F[x-1] * x;
    for (int n = 1; n < 800; n++) {
        for (int r = 1; r <= n; r++) {
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
