// https://atcoder.jp/contests/abc310/tasks/abc310_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<mint>> dp(N+1, vector<mint>((1 << 11), 0));
    dp[0][1] = 1;
    for (int i = 0; i < N; i++) {
        mint p = ((mint)A[i]).inv();
        for (ll s = 0; s < (1 << 11); s++) {
            for (ll a = 1; a <= min(10LL, A[i]); a++) {
                ll t = s;
                for (ll k = 0; k+a <= 10; k++) {
                    if (s & (1 << k)) t |= (1 << (k+a));
                }
                dp[i+1][t] += dp[i][s]*p;
            }
            if (A[i] > 10) dp[i+1][s] += dp[i][s]*(A[i]-10)*p;
        }
    }

    mint ans = 0;
    for (ll s = 0; s < (1 << 11); s++) if (s & (1 << 10)) ans += dp[N][s];
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
