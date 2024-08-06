// https://atcoder.jp/contests/abc137/tasks/abc137_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;
bool chmax(ll &l, ll r) {
    if (l < r) {
        l = r;
        return true;
    }
    return false;
}

void solve() {
    ll N, M, P;
    cin >> N >> M >> P;
    vector<ll> A(M), B(M), C(M);
    vector<vector<ll>> G(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        G[B[i]].push_back(A[i]);
    }

    vector<bool> reached(N, false);
    reached[N-1] = true;
    queue<ll> Q;
    Q.push(N-1);
    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (reached[v]) continue;
            reached[v] = true;
            Q.push(v);
        }
    }

    vector<ll> dp(N, -INF);
    ll ans = 0;
    dp[0] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < M; i++) {
            if (dp[A[i]] == -INF) continue;
            if (chmax(dp[B[i]], dp[A[i]] + C[i] - P)) {
                if (k == N-1 && reached[B[i]]) {
                    cout << -1 << endl;
                    return;
                }
                if (B[i] == N-1) chmax(ans, dp[B[i]]);
            }
        }
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
