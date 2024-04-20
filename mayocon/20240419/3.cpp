// https://atcoder.jp/contests/abc255/tasks/abc255_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll X, A, D, N;

ll f(ll i) {
    if (i < 0) return -4e+18;
    if (i >= N) return 4e+18;
    return A + i*D;
}

void solve() {
    cin >> X >> A >> D >> N;

    if (D < 0) {
        A = A + D * (N-1);
        D *= -1;
    }

    ll l = -1, r = N;
    while (r - l > 1) {
        ll m = (r+l)/2;
        if (f(m) <= X) l = m;
        else r = m;
    }
    ll ans = min(abs(X - f(l)), abs(X - f(r)));
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
