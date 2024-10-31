// https://atcoder.jp/contests/abc267/tasks/abc267_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    vector<ll> dp(M+1, -INF);
    dp[0] = 0;
    for (ll a : A) {
        vector<ll> ndp = dp;
        for (int i = 0; i < M; i++) {
            if (dp[i] == -INF) continue;
            ndp[i+1] = max(ndp[i+1], dp[i]+(i+1)*a);
        }
        swap(dp, ndp);
    }
    cout << dp[M] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
