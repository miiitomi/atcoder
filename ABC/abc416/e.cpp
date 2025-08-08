#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 1e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> d(N+1, vector<ll>(N+1, INF));
    for (int i = 0; i <= N; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c *= 2;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }
    ll K, T;
    cin >> K >> T;
    for (int i = 0; i < K; i++) {
        ll x;
        cin >> x;
        x--;
        d[x][N] = min(d[x][N], T);
        d[N][x] = min(d[N][x], T);
    }
    for (int i = 0; i <= N; i++) {
        for (int a = 0; a <= N; a++) {
            for (int b = 0; b <= N; b++) {
                d[a][b] = min(d[a][b], d[a][i]+d[i][b]);
            }
        }
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            ll x, y, t;
            cin >> x >> y >> t;
            x--; y--;
            t *= 2;
            d[x][y] = min(d[x][y], t);
            d[y][x] = min(d[y][x], t);
            for (int a = 0; a <= N; a++) {
                for (int b = 0; b <= N; b++) {
                    d[a][b] = min(d[a][b], min(d[a][x]+t+d[y][b], d[a][y]+t+d[x][b]));
                }
            }
        } else if (k == 2) {
            ll x;
            cin >> x;
            x--;
            d[x][N] = min(d[x][N], T);
            d[N][x] = min(d[N][x], T);
            for (int a = 0; a <= N; a++) {
                for (int b = 0; b <= N; b++) {
                    d[a][b] = min(d[a][b], min(d[a][x]+T+d[N][b], d[a][N]+T+d[x][b]));
                }
            }
        } else {
            ll ans = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (d[i][j] < INF) ans += d[i][j];
                }
            }
            cout << ans/2 << "\n";
        }
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
