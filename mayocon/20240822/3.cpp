// https://atcoder.jp/contests/abc057/tasks/abc057_b
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
    vector<ll> a(N), b(N), c(M), d(M);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for (int i = 0; i < M; i++) cin >> c[i] >> d[i];

    for (int i = 0; i < N; i++) {
        ll x = a[i], y = b[i];
        ll tmp = INF, ans = -1;
        for (int j = 0; j < M; j++) {
            if (tmp > abs(x-c[j])+abs(y-d[j])) {
                tmp = abs(x-c[j])+abs(y-d[j]);
                ans = j;
            }
        }
        cout << ans+1 << "\n";
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
