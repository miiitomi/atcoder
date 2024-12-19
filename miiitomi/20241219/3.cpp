// https://atcoder.jp/contests/abc108/tasks/arc102_a
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
    ll ans = (N / K) * (N / K) * (N / K);
    if (K % 2 == 0) {
        ll tmp = 0;
        for (ll x = K/2; x <= N; x += K) {
            tmp++;
        }
        ans += tmp*tmp*tmp;
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
