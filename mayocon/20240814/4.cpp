// https://atcoder.jp/contests/abc296/tasks/abc296_d
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
    if (N < 1e+6 && N*N < M) {
        cout << -1 << endl;
        return;
    }
    ll ans = INF;
    for (ll a = 1; a <= N; a++) {
        ll b = (M+a-1)/a;
        if (a <= N && b <= N) ans = min(ans, a*b);

        if (a*a > M) break;
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
