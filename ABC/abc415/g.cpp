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
    vector<int> P(301, -1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        P[a] = max(P[a], b);
    }

    vector<ll> dp(2e+5, -INF);
    for (ll a = 0; a <= 300; a++) {
        if (P[a] < 0) continue;
        ll b = P[a];
        ll left = 0, right = N/(a - b) + 1;
        while (right - left > 1) {
            ll m = (left + right) / 2;
            if (N + m*(b-a) > (ll)1e+5) left = m;
            else right = m;
        }
        ll tmp = N + left * b;
        dp[N + left * (b-a)] = max(dp[N + left * (b-a)], tmp);
    }

    for (int i = (ll)2e+5 - 1; i >= 0; i--) {
        if (dp[i] < 0) continue;
        for (ll a = 0; a <= 300; a++) {
            if (P[a] < 0) continue;
            ll b = P[a];
            if (i >= a) {
                dp[i-a+b] = max(dp[i-a+b], dp[i]+b);
            }
        }
    }

    ll ans = *max_element(dp.begin(), dp.end());
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
