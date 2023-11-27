// https://atcoder.jp/contests/abc175/tasks/abc175_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    __int128_t X, K, D;
    ll x, k, d;
    cin >> x >> k >> d;
    X = x;
    K = k;
    D = d;

    if (abs(X) >= K*D) {
        cout << (ll)abs(abs(X) - K*D) << endl;
        return 0;
    }

    __int128_t l = 0, r = K, m = 0;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (abs(X) < m*D) {
            r = m;
        } else {
            l = m;
        }
    }

    if (X > 0) X -= l*D;
    else X += l*D;
    K -= l;

    if (X == 0) {
        if (K % 2 == 0) cout << 0 << endl;
        else cout << (ll)D << endl;
    } else if (X > 0) {
        if (K % 2 == 0) cout << (ll)X << endl;
        else cout << (ll)abs(X - D) << endl;
    } else {
        if (K % 2 == 0) cout << (ll)abs(X) << endl;
        else cout << (ll)abs(X + D) << endl;
    }
}
