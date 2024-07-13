// https://atcoder.jp/contests/abc075/tasks/abc075_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 8e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    ll ans = INF;
    for (int i0 = 0; i0 < N; i0++) {
        for (int i1 = i0+1; i1 < N; i1++) {
            for (int j0 = 0; j0 < N; j0++) {
                for (int j1 = 0; j1 < N; j1++) {
                    ll sx = min(x[i0], x[i1]), sy = min(y[j0], y[j1]), tx = max(x[i0], x[i1]), ty = max(y[j0], y[j1]);
                    ll cnt = 0;
                    for (int k = 0; k < N; k++) {
                        if (sx <= x[k] && x[k] <= tx && sy <= y[k] && y[k] <= ty) cnt++;
                    }
                    if (cnt >= K) {
                        ans = min(ans, (tx-sx)*(ty-sy));
                    }
                }
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
