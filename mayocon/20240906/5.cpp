// https://atcoder.jp/contests/abc359/tasks/abc359_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, K;
bool is_palindrome(ll s) {
    for (int i = 0; i < K/2; i++) {
        if ((bool)(s & (1 << i)) != (bool)(s & (1 << (K-1-i)))) return false;
    }
    return true;
}

void solve() {
    cin >> N >> K;
    string S;
    cin >> S;
    vector<mint> dp(1 << K, 0);
    for (ll s = 0; s < (1 << K); s++) {
        if (is_palindrome(s)) continue;
        bool ok = true;
        for (int i = 0; i < K; i++) {
            if ((s & (1 << i)) && (S[i] == 'A')) ok = false;
            if (!(s & (1 << i)) && (S[i] == 'B')) ok = false;
        }
        if (ok) dp[s]++;
    }
    for (int i = K; i < N; i++) {
        vector<mint> ndp(1 << K, 0);
        for (ll s = 0; s < (1 << K); s++) {
            if (S[i] != 'B') ndp[s >> 1] += dp[s];
            if (S[i] != 'A') ndp[(s >> 1) | (1 << (K-1))] += dp[s];
        }
        for (ll s = 0; s < (1 << K); s++) {
            if (is_palindrome(s)) {
                ndp[s] = 0;
            }
        }
        swap(dp, ndp);
    }
    mint ans = 0;
    for (ll s = 0; s < (1 << K); s++) ans += dp[s];
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
