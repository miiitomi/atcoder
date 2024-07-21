// https://atcoder.jp/contests/abc341/tasks/abc341_f
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
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<ll> W(N), A(N);
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> V(N, 0);
    vector<ll> I(N);
    for (int i = 0; i < N; i++) I[i] = i;
    sort(I.begin(), I.end(), [&](int l, int r) {return W[l] < W[r];});

    for (int i : I) {
        ll w = W[i];
        vector<ll> dp(w, -INF);
        dp[0] = 0;
        for (ll u : G[i]) {
            if (W[u] >= w) continue;
            for (int m = w-1; m >= 0; m--) {
                if (m + W[u] >= w) continue;
                dp[m+W[u]] = max(dp[m+W[u]], dp[m] + V[u]);
            }
        }
        V[i] = *max_element(dp.begin(), dp.end()) + 1;
    }

    ll ans = 0;
    for (int u = 0; u < N; u++) ans += A[u]*V[u];
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
