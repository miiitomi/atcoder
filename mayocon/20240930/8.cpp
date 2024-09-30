// https://atcoder.jp/contests/abc260/tasks/abc260_g
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
    vector<string> S(N);
    for (string &s : S) cin >> s;
    vector<vector<ll>> plus(N+M, vector<ll>(N+2*M)), minus(N+M, vector<ll>(N+2*M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'X') continue;
            plus[i][j]++;
            plus[i+M][j]--;
            minus[i][j+2*M]--;
            minus[i+M][j]++;
        }
    }
    vector<vector<ll>> dp(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N+2*M; j++) {
            plus[i+1][j] += plus[i][j];
            if (j >= 2) minus[i+1][j-2] += minus[i][j];
            if (j < N) dp[i][j] += plus[i][j] + minus[i][j];
            if (j+1 < N) dp[i][j+1] += dp[i][j];
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << dp[x][y] << "\n";
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
