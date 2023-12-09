// https://atcoder.jp/contests/abc121/tasks/abc121_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    ll ans = 0;
    for (int k = 0; k < 60; k++) {
        if (k == 0) {
            ll y = (x >> 1LL) + 1;
            if (x % 2 == 0) y--;
            if (y % 2 == 1) ans++;
        }
        if (x & (1LL << k)) {
            if (x % 2 == 0) ans += (1LL << k);
        }
    }
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;

    if (a == 0) {
        cout << f(b) << endl;
    } else {
        cout << (ll)(f(b)^f(a-1)) << endl;
    }
}
