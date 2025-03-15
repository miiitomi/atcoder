#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

__uint128_t f(__uint128_t x) {
    return x*x*x;
}

void solve() {
    ll N;
    cin >> N;
    __uint128_t _n = N;
    for (__uint128_t d = 1; f(d) < _n; d++) {
        __uint128_t left = 0, right = 2e+9;
        while (right - left > 1) {
            __uint128_t k = (left + right) / 2;
            if (f(k+d) - f(k) > _n) right = k;
            else left = k;
        }

        if (f(left + d) - f(left) == _n) {
            ll x = left + d, y = left;
            cout << x << " " << y << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
