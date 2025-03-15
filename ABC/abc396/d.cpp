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
    vector<vector<ll>> A(N, vector<ll>(N, -1));
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        A[u-1][v-1] = w;
        A[v-1][u-1] = w;
    }

    if (N == 2) {
        cout << A[0][1] << "\n";
        return;
    }

    ll ans = INF;
    if (A[0][N-1] != -1) ans = A[0][N-1];

    for (ll s = 1; s < (1LL << (N-2)); s++) {
        vector<ll> v;
        for (int i = 0; i < N-2; i++) {
            if (s & (1 << i)) v.push_back(i+1);
        }
        do {
            ll tmp_u = 0, tmp_s = 0;
            for (ll i : v) {
                if (A[tmp_u][i] == -1) {
                    tmp_s = -1;
                    break;
                }
                tmp_s ^= A[tmp_u][i];
                tmp_u = i;
            }

            if (tmp_s == -1 || A[tmp_u][N-1] == -1) continue;
            tmp_s ^= A[tmp_u][N-1];
            ans = min(ans, tmp_s);
        } while (next_permutation(v.begin(), v.end()));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
