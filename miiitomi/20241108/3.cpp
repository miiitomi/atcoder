// https://atcoder.jp/contests/abc085/tasks/abc085_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, H;
    cin >> N >> H;
    priority_queue<ll> Q;
    ll a = -1;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        a = max(a, x);
        Q.push(y);
    }
    ll ans = (H + a - 1)/ a;
    for (int k = 1; k <= N; k++) {
        H = max(H-Q.top(), 0LL);
        Q.pop();
        ans = min(ans, (H + a - 1)/a + k);
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
