#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

ll modinv(ll a) {
    // Check if a and MOD are coprime.
    ll b = MOD, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}


int main() {
    for (ll a = 1; a <= 10; a++) {
        cout << "a = " << a << " :  modinv(a) = " << modinv(a) << endl;
    }
}
