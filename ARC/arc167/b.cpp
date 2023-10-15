#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint998244353;

int main() {
    bool is_odd = true;
    ll A, b;
    cin >> A >> b;
    if (b % 2 == 0) is_odd = false;
    mint B = b;
    map<ll,ll> M;
    for (ll x = 2; x*x <= A; x++) {
        while (A % x == 0) {
            M[x]++;
            A /= x;
        }
    }
    if (A != 1) M[A] = 1;

    mint ans = B;
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        ans *= B * iter->second + 1;
        if (iter->second % 2 == 1) is_odd = false;
    }

    if (is_odd) ans -= 1;
    ans /= 2;

    cout << ans.val() << endl;
}
