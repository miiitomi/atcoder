#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    if (H < W) {
        vector<string> T(W, string(H, '.'));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                T[j][i] = S[i][j];
            }
        }
        swap(S, T);
        swap(H, W);
    }
    ll p = 1;
    for (int k = 0; k < W; k++) p *= 10;
    vector<vector<map<ll, mint>>> dp(H, vector<map<ll,mint>>(W, map<ll, mint>()));
    for (ll c = 1; c <= 3; c++) {
        if (S[0][0] == (char)('0'+c) || S[0][0] == '?') dp[0][0][c] = 1;
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) continue;
            int pi = i, pj = j;
            if (j == 0) {
                pi--;
                pj = W-1;
            } else pj--;
            for (auto iter = dp[pi][pj].begin(); iter != dp[pi][pj].end(); iter++) {
                ll s = iter->first;
                mint v = iter->second;
                for (ll c = 1; c <= 3; c++) {
                    if (S[i][j] != '?' && S[i][j] != (char)('0' + c)) continue;
                    if (i == 0 && s%10 != c) dp[i][j][(s*10 + c) % p] += v;
                    else if (i > 0) {
                        bool ok = (s/(p/10) != c);
                        if (j != 0 && s%10 == c) ok = false;
                        if (ok) dp[i][j][(s*10 + c) % p] += v;
                    }
                }
            }
        }
    }
    mint ans = 0;
    for (auto iter = dp.back().back().begin(); iter != dp.back().back().end(); iter++) ans += iter->second;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
