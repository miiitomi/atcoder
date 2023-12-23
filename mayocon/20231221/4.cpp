// https://atcoder.jp/contests/abc238/tasks/abc238_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
    ll a, s;
    cin >> a >> s;
    ll x = 0, y = 0, z = 0;
    for (ll k = 0; k <= 61; k++) {
        if (k == 0) {
            if (a & 1) {
                if (s & 1) return false;
                x = 1;
                y = 1;
                z = 2;
            } else {
                if (s & 1) x = 1;
            }
        } else {
            if (a & (1LL << k)) {
                x += (1LL << k);
                y += (1LL << k);
                if ((s & (1LL << k)) != (z & (1LL << k))) return false;
                z = (1LL << (k+1));
            } else {
                if ( (s & (1LL << k)) != (z & (1LL << k)) ) x += (1LL << k);
                if ((x & (1LL << k)) && (z & (1LL << k)) ) z = (1LL << (k+1));
            }
        }
    }

    return s == x+y;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        if (solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
