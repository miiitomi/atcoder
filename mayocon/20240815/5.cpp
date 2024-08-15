// https://atcoder.jp/contests/abc113/tasks/abc113_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, K;
    cin >> H >> W >> K;
    K--;
    vector<mint> dp(W, 0);
    dp[0] = 1;

    vector<ll> v;
    for (ll s = 0; s < (1 << (W-1)); s++) {
        vector<ll> w;
        for (int i = 0; i < W-1; i++) {
            if (s & (1 << i)) w.push_back(i);
        }
        bool is_ok = true;
        for (int j = 0; j < (int)w.size()-1; j++) {
            if (abs(w[j] - w[j+1]) == 1) is_ok = false;
        }
        if (is_ok) v.push_back(s);
    }

    while (H--) {
        vector<mint> ndp(W, 0);
        for (ll s : v) {
            for (int i = 0; i < W; i++) {
                if (i != W-1 && s & (1 << i)) {
                    ndp[i+1] += dp[i];
                } else if (i != 0 && s & (1 << (i-1))) {
                    ndp[i-1] += dp[i];
                } else {
                    ndp[i] += dp[i];
                }
            }
        }
        swap(dp, ndp);
    }

    cout << dp[K].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
