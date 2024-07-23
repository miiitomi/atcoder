// https://atcoder.jp/contests/abc121/tasks/abc121_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll g(ll B) {
    ll ans = (B%4 == 1 || B%4 == 2);
    for (ll k = 1; k < 50; k++) {
        if (B & (1LL << k)) {
            ans += (1LL << k) * (B%2 == 0);
        }
    }
    return ans;
}

void solve() {
    ll A, B;
    cin >> A >> B;
    ll ans;
    if (A == 0) ans = g(B);
    else ans = g(B)^g(A-1);
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
