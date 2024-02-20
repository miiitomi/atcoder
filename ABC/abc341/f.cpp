#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;
vector<vector<ll>> G;
vector<ll> W, A;

void solve() {
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }
    W.resize(N);
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> dp(N, 0);
    auto cmp = [&](const int i, const int j) {return W[i] < W[j];};
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    sort(v.begin(), v.end(), cmp);

    ll ans = 0;
    for (int i : v) {
        vector<ll> dp2(W[i], 0);
        for (int j : G[i]) {
            vector<ll> ndp2 = dp2;
            if (W[j] >= W[i]) continue;
            for (int w = 0; w < W[i]; w++) {
                if (w + W[j] >= W[i]) break;
                ndp2[w + W[j]] = max(ndp2[w + W[j]], dp2[w] + dp[j]);
            }
            swap(dp2, ndp2);
        }
        dp[i] = *max_element(dp2.begin(), dp2.end()) + 1;
        ans += A[i] * dp[i];
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
