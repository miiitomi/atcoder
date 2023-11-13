// https://atcoder.jp/contests/abc166/tasks/abc166_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;

    bool pos = false;
    for (ll b = 0; b < 100000; b++) {
        ll B = b*b*b*b*b;
        if (!pos) B = -B;
        ll C = X + B;
        for (ll a = 0; a < 100000; a++) {
            ll A = a*a*a*a*a;

            if (A == C) {
                if (pos || b == 0) cout << a << " " << b << endl;
                else cout << a << " " << -b << endl;
                return 0;
            } else if (A > C) {
                break;
            }
        }

        for (ll a = -1; a >= -100000; a--) {
            ll A = a*a*a*a*a;

            if (A == C) {
                if (pos || b == 0) cout << a << " " << b << endl;
                else cout << a << " " << -b << endl;
                return 0;
            } else if (A < C) {
                break;
            }
        }

        if (pos) {
            pos = false;
            b--;
        } else {
            pos = true;
        }
    }
}
