#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

vector<mint> F(2001, 1);

mint comb(int n, int r) {
    return F[n]/(F[n-r]*F[r]);
}

vector<vector<mint>> com(2001, vector<mint>(2001, 0));

void solve() {
    int K;
    cin >> K;
    vector<int> C(26);
    for (int i = 0; i < 26; i++) cin >> C[i];

    vector<vector<mint>> dp(27, vector<mint>(K+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int x = 0; x <= K; x++) {
            for (int c = 0; c <= C[i]; c++) {
                if (x + c > K) continue;
                dp[i+1][x+c] += dp[i][x] * com[x+c][c];
            }
        }
    }

    mint ans = 0;
    for (int x = 1; x <= K; x++) ans += dp[26][x];
    cout << ans.val() << endl;
}

int main() {
    for (int x = 1; x <= 2000; x++) F[x] = x * F[x-1];
    for (int n = 0; n <= 2000; n++) {
        for (int r = 0; r <= n; r++) {
            com[n][r] = comb(n, r);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
