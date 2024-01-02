// https://atcoder.jp/contests/abc108/tasks/abc108_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double d(ll x, ll y) {
    return sqrt(0.0+ x*x + y*y);
}

int main() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;

    for (ll a = -1000; a <= 1000; a++) {
        for (ll b = -1000; b <= 1000; b++) {
            ll A1 = a - x2, B1 = b - y2, A2 = x1 - x2, B2 = y1 - y2;
            if (A1 * A2 + B1 * B2 == 0 && A1*B2 - A2*B1 > 0 && abs(d(A1, B1) - d(A2, B2)) < 1e-5) {
                x3 = a;
                y3 = b;
                goto here1;
            }
        }
    }

    here1:

    for (ll a = -1000; a <= 1000; a++) {
        for (ll b = -1000; b <= 1000; b++) {
            ll A1 = a - x3, B1 = b - y3, A2 = x2 - x3, B2 = y2 - y3;
            if (A1 * A2 + B1 * B2 == 0 && A1*B2 - A2*B1 > 0 && abs(d(A1, B1) - d(A2, B2)) < 1e-5) {
                x4 = a;
                y4 = b;
                goto here2;
            }
        }
    }

    here2:

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
