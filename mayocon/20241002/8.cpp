// https://atcoder.jp/contests/abc128/tasks/abc128_f
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
    vector<ll> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];
    vector<vector<ll>> dp(N-1);
    ll ans = -INF;
    for (ll c = 1; c < N-1; c++) {
        dp[c].push_back(s[0]+s[N-1]);
        set<ll> st{0, N-1};
        for (ll k = 1; (k+1)*c < N-1; k++) {
            if (st.contains(N-1-k*c)) break;
            st.insert(N-1-k*c);
            if (st.contains(k*c)) break;
            st.insert(k*c);
            dp[c].push_back(dp[c].back() + s[N-1-k*c] + s[k*c]);
        }
        ans = max(ans, *max_element(dp[c].begin(), dp[c].end()));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
