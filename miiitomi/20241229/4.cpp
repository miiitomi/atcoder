// https://atcoder.jp/contests/abc074/tasks/arc083_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<vector<bool>> dp(F+1, vector<bool>(F+1, false));
    dp[0][0] = true;
    for (int w = 0; w <= F; w++) {
        for (int s = 0; s <= F; s++) {
            if (!dp[w][s]) continue;
            if (w + 100*A <= F) dp[w+100*A][s] = true;
            if (w + 100*B <= F) dp[w+100*B][s] = true;
            if (s + C <= F) dp[w][s+C] = true;
            if (s + D <= F) dp[w][s+D] = true;
        }
    }
    dp[0][0] = false;
    ll a = 100*A, b = 0;
    for (ll w = 0; w <= F; w++) {
        for (ll s = 0; s <= F; s++) {
            if (!dp[w][s] || w+s > F || s > (w/100)*E) continue;
            if (100*b*(w+s) < (a+b)*100*s) {
                a = w;
                b = s;
            }
        }
    }
    cout << a+b << " " << b << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
