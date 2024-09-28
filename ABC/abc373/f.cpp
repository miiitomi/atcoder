#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, W;
    cin >> N >> W;
    vector<priority_queue<ll>> V(W+1);
    for (int i = 0; i < N; i++) {
        ll w, v;
        cin >> w >> v;
        V[w].push(v-1);
    }
    vector<pair<ll,ll>> P;
    for (ll w = 1; w <= W; w++) {
        if (V[w].empty()) continue;
        ll cnt = 0;
        while (cnt < W && V[w].top() > 0) {
            ll x = V[w].top();
            V[w].pop();
            P.push_back({x, w});
            V[w].push(x-2);
            cnt += w;
        }
    }
    vector<ll> dp(W+1, 0);
    for (int i = 0; i < (int)P.size(); i++) {
        vector<ll> ndp = dp;
        for (int j = P[i].second; j <= W; j++) {
            ndp[j-P[i].second] = max(ndp[j-P[i].second], dp[j] + P[i].first);
        }
        swap(dp, ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
