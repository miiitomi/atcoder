// https://atcoder.jp/contests/abc090/tasks/arc091_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    if (K == 0) {
        cout << N*N << "\n";
        return;
    }
    ll ans = 0;
    for (ll b = K+1; b <= N; b++) {
        ll x = (N/b);
        ans += x*(b-1 - K + 1);
        ll r = N%b;
        if (K <= r) ans += r - K + 1;
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
