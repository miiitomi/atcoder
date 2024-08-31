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
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    vector<ll> U(M), V(M), T(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i] >> T[i];
        U[i]--; V[i]--;
        dist[U[i]][V[i]] = min(dist[U[i]][V[i]], T[i]);
        dist[V[i]][U[i]] = min(dist[V[i]][U[i]], T[i]);
    }
    for (int i = 0; i < N; i++) {
        vector<vector<ll>> nd = dist;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                nd[j][k] = min(nd[j][k], dist[j][i] + dist[i][k]);
            }
        }
        swap(nd, dist);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        ll K;
        cin >> K;
        vector<ll> B(K);
        for (int k = 0; k < K; k++) {
            cin >> B[k];
            B[k]--;
        }
        ll ans = INF;
        for (ll s = 0; s < (1 << K); s++) {
            vector<ll> v(K);
            iota(v.begin(), v.end(), 0);
            do {
                ll tmp = 0;
                ll cur = 0;
                for (int k = 0; k < K; k++) {
                    int i = v[k];
                    ll u = U[B[i]], v = V[B[i]], t = T[B[i]];
                    if (s & (1 << k)) swap(u, v);
                    tmp += dist[cur][u] + t;
                    cur = v;
                }
                tmp += dist[cur][N-1];
                ans = min(ans, tmp);
            } while (next_permutation(v.begin(), v.end()));
        }
        cout << ans << "\n";
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
