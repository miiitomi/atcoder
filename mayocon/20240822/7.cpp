// https://atcoder.jp/contests/abc235/tasks/abc235_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> ten_pow(1e5, 1);

void solve() {
    string S;
    ll N, M;
    cin >> S >> M;
    N = S.size();
    vector<int> C(M), d(10, -1);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
        d[C[i]] = i;
    }

    vector<vector<pair<mint,mint>>> dp(2, vector<pair<mint,mint>>(1 << M, {0, 0}));
    for (int x = 1; x < S[0]-'0'; x++) {
        int j = 0;
        if (d[x] != -1) j = (1 << d[x]);
        dp[0][j].first += 1;
        dp[0][j].second += x * ten_pow[N-1];
    }
    int j = 0;
    if (d[S[0]-'0'] != -1) j = (1 << d[S[0]-'0']);
    dp[1][j].first += 1;
    dp[1][j].second += (S[0]-'0') * ten_pow[N-1];

    for (int i = 1; i < N; i++) {
        int x = S[i]-'0';
        vector<vector<pair<mint,mint>>> ndp(2, vector<pair<mint,mint>>(1 << M, {0, 0}));
        for (int y = 1; y <= 9; y++) {
            int j = 0;
            if (d[y] != -1) j = (1 << d[y]);
            ndp[0][j].first += 1;
            ndp[0][j].second += y * ten_pow[N-1-i];
        }

        for (int s = 0; s < (1 << M); s++) {
            for (int y = 0; y <= 9; y++) {
                int j = 0;
                if (d[y] != -1) j = (1 << d[y]);
                ndp[0][s | j].first += dp[0][s].first;
                ndp[0][s | j].second += dp[0][s].second + dp[0][s].first*y*ten_pow[N-1-i];
                if (y < x) {
                    ndp[0][s | j].first += dp[1][s].first;
                    ndp[0][s | j].second += dp[1][s].second + dp[1][s].first*y*ten_pow[N-1-i];
                } else if (y == x) {
                    ndp[1][s | j].first += dp[1][s].first;
                    ndp[1][s | j].second += dp[1][s].second + dp[1][s].first*y*ten_pow[N-1-i];
                }
            }
        }
        swap(dp, ndp);
    }

    mint ans = dp[0][(1 << M)-1].second + dp[1][(1 << M)-1].second;
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x < 1e+5; x++) ten_pow[x] = 10 * ten_pow[x-1];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
