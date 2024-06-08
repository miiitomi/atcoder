#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;

mint mod_pow(mint a, ll n) {
    if (n == 0) return 1;
    mint res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

void solve() {
    ll N;
    cin >> N;

    ll x = N;
    ll K = 0;
    while (x > 0) {
        x /= 10;
        K++;
    }

    mint K10 = mod_pow((mint)(10), K);

    mint ans = ((mod_pow(K10, N) - (mint)(1)) / (K10 - (mint)1)) * N;
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
