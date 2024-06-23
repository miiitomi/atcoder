#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

bool is_kaibun(string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<map<string,mint>> dp(N+1);
    for (int s = 0; s < (1 << K); s++) {
        bool is_ok = true;
        string x;
        for (int i = 0; i < K; i++) {
            if (s & (1 << i)) {
                x.push_back('B');
                if (S[i] == 'A') is_ok = false;
            } else {
                x.push_back('A');
                if (S[i] == 'B') is_ok = false;
            }
        }
        if (is_kaibun(x)) is_ok = false;
        if (!is_ok) continue;
        dp[K][x] = 1;
    }

    for (int i = K; i < N; i++) {
        for (auto iter = dp[i].begin(); iter != dp[i].end(); iter++) {
            mint tmp = iter->second;
            string x = iter->first;
            if (S[i] != 'A') {
                string y = x;
                reverse(y.begin(), y.end());
                y.pop_back();
                reverse(y.begin(), y.end());
                y.push_back('B');
                if (!is_kaibun(y)) {
                    dp[i+1][y] += tmp;
                }
            }
            if (S[i] != 'B') {
                string y = x;
                reverse(y.begin(), y.end());
                y.pop_back();
                reverse(y.begin(), y.end());
                y.push_back('A');
                if (!is_kaibun(y)) {
                    dp[i+1][y] += tmp;
                }
            }
        }
    }

    mint ans = 0;
    for (auto iter = dp[N].begin(); iter != dp[N].end(); iter++) {
        ans += iter->second;
    }
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
