#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> void chmin(T &v, T nv) {
    if (v > nv) v = nv;
}

void solve() {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> A(M), B(M), C(M), D(M, 1);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
    }
    vector<vector<ll>> Queries(Q);
    for (int i = 0; i < Q; i++) {
        ll t;
        cin >> t;
        if (t == 1) {
            Queries[i].resize(1);
            cin >> Queries[i][0];
            Queries[i][0]--;
            D[Queries[i][0]] = 0;
        } else {
            Queries[i].resize(2);
            cin >> Queries[i][0] >> Queries[i][1];
            Queries[i][0]--; Queries[i][1]--;
        }
    }
    vector<vector<ll>> dp(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int i = 0; i < M; i++) {
        if (D[i] == 0) continue;
        dp[A[i]][B[i]] = C[i];
        dp[B[i]][A[i]] = C[i];
    }
    for (int i = 0; i < N; i++) {
        vector<vector<ll>> ndp = dp;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                chmin(ndp[j][k], dp[j][i] + dp[i][k]);
            }
        }
        swap(dp, ndp);
    }
    reverse(Queries.begin(), Queries.end());
    for (auto &v : Queries) {
        if ((int)v.size() == 1) {
            ll a = A[v[0]], b = B[v[0]], c = C[v[0]];
            vector<vector<ll>> ndp = dp;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    chmin(ndp[i][j], dp[i][a] + c + dp[b][j]);
                    chmin(ndp[i][j], dp[i][b] + c + dp[a][j]);
                }
            }
            swap(dp, ndp);
        } else {
            ll a = v[0], b = v[1];
            v.push_back(dp[a][b]);
        }
    }
    reverse(Queries.begin(), Queries.end());
    for (auto &v : Queries) {
        if ((int)v.size() == 1) continue;
        if (v.back() >= INF/2) cout << -1 << "\n";
        else cout << v.back() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
