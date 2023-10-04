// https://atcoder.jp/contests/abc196/tasks/abc196_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    ll left = -1e18, right = 1e+18, vl = -1e18, vr = 1e+18;
    for (int k = 0; k < N; k++) {
        ll a, t;
        cin >> a >> t;

        if (t == 1) {
            vl += a;
            vr += a;
        } else {
            if ((t == 3 && vl >= a) || (t == 2 && a >= vr)) {
                left = 0;
                right = 0;
                vl = a;
                vr = a;
            }
            else if (!(vl <= a && a <= vr)) continue;

            ll x = left + (a - vl);
            if (t == 2) {
                left = x;
                vl = a;
            } else {
                right = x;
                vr = a;
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        ll x;
        cin >> x;
        if (x <= left) cout << vl << endl;
        else if (x >= right) cout << vr << endl;
        else {
            cout << vl + (x - left) << endl;
        }
    }
}
