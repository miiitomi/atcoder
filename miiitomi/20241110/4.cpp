// https://atcoder.jp/contests/abc265/tasks/abc265_e
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
    vector<pair<ll,ll>> P(3);
    for (int k = 0; k < 3; k++) cin >> P[k].first >> P[k].second;
    set<pair<ll,ll>> st;
    for (int i = 0; i < M; i++) {
        ll x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    vector<map<pair<ll,ll>, mint>> dp(N+1);
    dp[0][{0, 0}] = 1;
    for (int i = 0; i < N; i++) {
        for (auto iter = dp[i].begin(); iter != dp[i].end(); iter++) {
            auto [x, y] = iter->first;
            mint v = iter->second;
            for (int k = 0; k < 3; k++) {
                ll a = x + P[k].first, b = y + P[k].second;
                if (st.contains({a, b})) continue;
                dp[i+1][{a, b}] += v;
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
