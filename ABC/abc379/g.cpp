#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<string> v;
void f(string &S) {
    if ((int)S.size() == W) {
        v.push_back(S);
        return;
    }
    for (char c = '1'; c <= '3'; c++) {
        if (S.empty() || S.back() != c) {
            S.push_back(c);
            f(S);
            S.pop_back();
        }
    }
}

void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    if (H < W) {
        vector<string> T(W, string(H, '1'));
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) T[j][i] = S[i][j];
        swap(H, W);
        swap(S, T);
    }
    string T = "";
    f(T);
    sort(v.begin(), v.end());
    int N = v.size();
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        string s = v[i];
        for (int j = i+1; j < N; j++) {
            string t = v[j];
            bool ok = true;
            for (int k = 0; k < (int)s.size(); k++) {
                if (s[k] == t[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    vector<mint> dp(v.size(), 1);
    for (int i = 0; i < (int)v.size(); i++) {
        bool ok = true;
        for (int j = 0; j < W; j++) {
            if (S[0][j] != '?' && S[0][j] != v[i][j]) {
                ok = false;
                break;
            }
        }
        if (!ok) dp[i] = 0;
    }
    for (int i = 1; i < H; i++) {
        vector<mint> ndp(v.size(), 0);
        for (int j = 0; j < (int)v.size(); j++) {
            bool ok = true;
            for (int k = 0; k < W; k++) {
                if (S[i][k] != '?' && S[i][k] != v[j][k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int k : G[j]) {
                ndp[j] += dp[k];
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for (mint x : dp) ans += x;
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
