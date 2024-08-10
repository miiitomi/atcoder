#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> C(N);
    for (int i = 0; i < N; i++) cin >> C[i].first >> C[i].second;
    sort(C.begin(), C.end(), [](const pair<ll,ll> &l, const pair<ll,ll> &r) {
        return (l.first-1)*r.second < (r.first-1)*l.second;
    });
    vector<ll> dp(K+1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = K-1; j >= 0; j--) {
            if (dp[j] == 0) continue;
            dp[j+1] = max(dp[j+1], C[i].first*dp[j]+C[i].second);
        }
    }
    cout << dp.back() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
