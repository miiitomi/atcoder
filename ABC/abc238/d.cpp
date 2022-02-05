#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll a, ll s) {
    ll x = 0;
    ll y = 0;
    ll c = 0;
    for (int i = 0; i < 63; i++) {
        if (a & (1LL << i)) {
            x += (1LL << i);
            y += (1LL << i);
            if (s & (1LL << i)) {
                if (c == 0) return false;
            }
            c = 1;
        } else {
            if (s & (1LL << i)) {
                if (c) {
                    c = 0;
                } else {
                    x += (1LL << i);
                }
            } else {
                if (c) {
                    x += (1LL << i);
                }
            }
        }
    }
    if ((x + y == s) && ((x & y) == a)) return true;
    else return false;
}

int main() {
    int T;
    cin >> T;
    vector<ll> a(T), s(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i] >> s[i];
    }

    for (int i = 0; i < T; i++) {
        if (f(a[i], s[i])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
