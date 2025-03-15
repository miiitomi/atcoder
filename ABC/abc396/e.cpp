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
    dsu U(N);
    vector<vector<pair<ll,ll>>> G(N);
    for (int i = 0; i < M; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
        U.merge(x, y);
    }

    vector<ll> A(N, 0);
    for (ll k = 0; k < 30; k++) {
        vector<vector<ll>> tmp(2, vector<ll>(N, -1));
        for (int r = 0; r < N; r++) {
            if (r != U.leader(r)) continue;
            vector<vector<ll>> reached(2);
            vector<ll> sum(2, 0);
            queue<int> Q;
            vector<bool> ok(2, true);
            for (ll f = 0; f <= 1; f++) {
                tmp[f][r] = f;
                reached[f].push_back(r);
                sum[f] = f;
                Q.push(r);
                while (!Q.empty() && ok[f]) {
                    ll u = Q.front();
                    Q.pop();
                    for (auto [v, z] : G[u]) {
                        if (tmp[f][v] != -1) {
                            if (tmp[f][v] != ((bool)(z & (1LL << k)) ^ tmp[f][u])) {
                                ok[f] = false;
                                break;
                            }
                        } else {
                            tmp[f][v] = ((bool)(z & (1LL << k)) ^ tmp[f][u]);
                            sum[f] += tmp[f][v];
                            reached[f].push_back(v);
                            Q.push(v);
                        }
                    }
                }
            }
            if (!ok[0] && !ok[1]) {
                cout << "-1\n";
                return;
            }
            int f;
            if (ok[0] && !ok[1]) f = 0;
            else if (ok[1] && !ok[0]) f = 1;
            else if (sum[0] < sum[1]) f = 0;
            else f = 1;

            for (int u : reached[f]) {
                if (tmp[f][u]) {
                    A[u] ^= (1LL << k);
                }
            }
        }
    }

    for (ll a : A) cout << a << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
