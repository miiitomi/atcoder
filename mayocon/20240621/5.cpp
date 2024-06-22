// https://atcoder.jp/contests/abc183/tasks/abc183_e
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    vector<vector<mint>> dp(H, vector<mint>(W, 0));
    dp[0][0] = 1;

    vector<mint> Yoko(1e+5, 0), Tate(1e+5, 0), Naname(1e+5, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                Yoko[i] = 0;
                Tate[j] = 0;
                Naname[H+W+i-j] = 0;
            }
            dp[i][j] += Yoko[i]+Tate[j]+Naname[H+W+i-j];
            Yoko[i] += dp[i][j];
            Tate[j] += dp[i][j];
            Naname[H+W+i-j] += dp[i][j];
        }
    }

    cout << dp.back().back().val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
