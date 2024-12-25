// https://atcoder.jp/contests/abc129/tasks/abc129_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    set<ll> st;
    while (M--) {
        ll a;
        cin >> a;
        st.insert(a);
    }
    vector<mint> dp(N+2, 0);
    dp[0] = 1;
    for (int x = 0; x < N; x++) {
        if (st.contains(x)) continue;
        dp[x+1] += dp[x];
        dp[x+2] += dp[x];
    }
    cout << dp[N].val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
