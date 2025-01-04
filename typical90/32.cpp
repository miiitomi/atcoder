// https://atcoder.jp/contests/typical90/tasks/typical90_af
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N)), B(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
    int M;
    cin >> M;
    while (M--) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        B[x][y] = 1;
        B[y][x] = 1;
    }
    vector<ll> v(N);
    iota(v.begin(), v.end(), 0);
    ll ans = INF;
    do {
        bool ok = true;
        for (int i = 0; i < N-1; i++) {
            int x = v[i], y = v[i+1];
            if (B[x][y]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            tmp += A[v[i]][i];
        }
        ans = min(ans, tmp);
    } while(next_permutation(v.begin(), v.end()));

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
