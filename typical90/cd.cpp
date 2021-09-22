#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MOD = 1000000007;

ull _pow(ull a, ull p) {
    if (p == (ull)0) return (ull)1;
    ull res = _pow(a * a, p / 2);
    if (p % (ull)2 == (ull)1) res = res * a;
    return res;
}

ull modpow(ull a, ull p, ull m) {
    if (p == 0) return (ull)1;
    ull res = modpow(a * a % m, p / 2, m);
    if (p % (ull)2 == (ull)1) res = res * a % m;
    return res;
}

ull modinv(ull a, ull m) {
    return modpow(a, m - 2, m);
}

int main() {
    ull L, R;
    cin >> L >> R;

    ull ans = 0;
    for (ull p = 1; p < 30; p++) {
        if (_pow((ull)10, p) <= L) continue;
        if (_pow((ull)10, p-1) > R) break;
        ull first = max(_pow((ull)10, p-1), L);
        ull last = min(_pow((ull)10, p) - 1, R);
        ull x = p * ((first + last) % MOD) % MOD;
        x = x * ((last - first + 1) % MOD) % MOD;
        x = x * modinv((ull)2, MOD) % MOD;
        ans = (ans + x) % MOD;
    }

    cout << ans << endl;
}
