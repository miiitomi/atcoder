// https://atcoder.jp/contests/abc194/tasks/abc194_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

string nums = "0123456789ABCDEF";

void solve() {
    string N;
    cin >> N;
    int K;
    cin >> K;
    vector<vector<mint>> dp(N.size(), vector<mint>(17, 0));
    set<char> st;
    for (int i = 0; i < (int)N.size(); i++) {
        for (char c : nums) {
            if (c == '0') continue;
            if (i == 0 && N[0] == c) break;
            dp[i][1] += 1;
        }
        if (i >= 1) {
            for (char c : nums) {
                if (c == N[i]) break;
                dp[i][(int)st.size() + (!st.contains(c))] += 1;
            }
        }
        st.insert(N[i]);
        if (i+1 < (int)N.size()) {
            for (int j = 1; j <= 16; j++) {
                dp[i+1][j] += dp[i][j] * j;
                dp[i+1][j+1] += dp[i][j] * (16 - j);
            }
        } else {
            dp[i][(int)st.size()] += 1;
        }
    }
    cout << dp.back()[K].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
