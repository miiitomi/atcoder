// https://atcoder.jp/contests/abc214/tasks/abc214_f
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

void solve() {
    string S;
    cin >> S;
    vector<vector<int>> v(26);
    for (int i = 0; i < (int)S.size(); i++) {
        v[S[i]-'a'].push_back(i+1);
    }

    vector<mint> dp(S.size()+1, 0);
    dp[0] = 1;
    for (int i = 0; i < (int)S.size(); i++) {
        for (int c = 0; c < 26; c++) {
            auto iter = lower_bound(v[c].begin(), v[c].end(), i+2-(i==0));
            if (iter != v[c].end()) {
                int j = *iter;
                dp[j] += dp[i];
            }
        }
    }
    mint ans = 0;
    for (int i = 1; i <= (int)S.size(); i++) ans += dp[i];
    cout << ans.val() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
