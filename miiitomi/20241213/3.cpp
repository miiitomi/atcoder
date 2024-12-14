// https://atcoder.jp/contests/abc049/tasks/arc065_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    vector<string> V{"dream", "dreamer", "erase", "eraser"};
    vector<bool> dp(S.size()+1, false);
    dp.back() = true;
    for (int i = S.size()-1; i >= 0; i--) {
        for (string &t : V) {
            if (i + t.size() > S.size() || !dp[i + t.size()]) continue;
            bool ok = true;
            for (int j = 0; j < (int)t.size(); j++) {
                if (S[i+j] != t[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                dp[i] = true;
                break;
            }
        }
    }
    if (dp[0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
