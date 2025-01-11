// https://atcoder.jp/contests/abc198/tasks/abc198_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll R, X, Y;
    cin >> R >> X >> Y;

    if (X*X+Y*Y < R*R) {
        cout << 2 << endl;
        return;
    }

    for (ll k = 1; k <= 1e+7; k++) {
        ll d = R*R*k*k;
        ll a = X*X + Y*Y;
        if (a <= d) {
            cout << k << endl;
            return;
        }
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
