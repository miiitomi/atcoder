// https://atcoder.jp/contests/abc255/tasks/abc255_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, A, D, N;

ll f(ll m) {
    return A + D * m;
}

int main() {
    cin >> X >> A >> D >> N;

    if (D < 0) {
        ll d = - D;
        A = f(N-1);
        D = d;
    }

    if (X <= f(0)) {
        cout << abs(f(0) - X) << endl;
        return 0;
    } else if (X >= f(N-1)) {
        cout << abs(f(N-1) - X) << endl;
        return 0;
    }

    ll l = -1, r = 1e+12;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll a = f(mid);
        if (a > X) r = mid;
        else l = mid;
    }

    l -= 2;
    ll ans = 2e+18;
    for (int k = 0; k < 3; k++) {
        l++;
        if (!(0 <= l && l < N)) continue;
        ans = min(ans, abs(X - f(l)));
    }
    cout << ans << endl;
}
