#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    l -= a;
    r -= a;

    ll ans = 0;

    if (l == r) {
        if (l % m == 0) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    if (l <= 0 && 0 <= r) {
        ans += r / m;
        ans += abs(l) / m;
        ans++;
        cout << ans << endl;
        return 0;
    }

    if (r <= 0) {
        ll L = abs(r), R = abs(l);
        l = L;
        r = R;
    }

    if (l == 0) {
        ans = r / m + 1;
    } else {
        ans = (r / m) - (l-1) / m;
    }

    cout << ans << endl;
}
