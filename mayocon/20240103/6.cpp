// https://atcoder.jp/contests/abc321/tasks/abc321_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, X, K;

ll f(ll x, ll k) {
    ll l = x, r = x+1;
    for (int i = 0; i < k; i++) {
        l *= 2;
        r *= 2;
        if (N < l) return 0;
        if (N < r) r = N+1;
    }
    return r - l;
}

void solve() {
    cin >> N >> X >> K;
    if (K == 0) {
        cout << 1 << endl;
        return;
    }

    ll ans = 0, c = -1;
    while (X >= 1 && K >= 0) {
        ans += f(X, K);
        if (c != -1 && K >= 1) ans -= f(c, K-1);
        c = X;
        X /= 2;
        K--;
    }

    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
