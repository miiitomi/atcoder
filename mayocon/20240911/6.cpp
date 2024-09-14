// https://atcoder.jp/contests/abc321/tasks/abc321_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N, X, K;

ll f(ll r, ll k) {
    ll mi = r, ma = r;
    for (int i = 0; i < k; i++) {
        mi = mi*2;
        if (mi > N) return 0;
        ma = min(ma*2 + 1, N);
    }
    return ma - mi + 1;
}

void solve() {
    cin >> N >> X >> K;
    ll pre = -1;
    ll ans = 0;
    for (ll k = 0; k <= K; k++) {
        if (X == 0) break;
        ans += f(X, K-k);
        if (0 < k && k < K) ans -= f(pre, K-k-1);
        pre = X;
        X /= 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
