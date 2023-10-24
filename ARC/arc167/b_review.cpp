#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    map<ll,ll> M;
    for (ll x = 2; x*x <= A; x++) {
        while (A % x == 0) {
            M[x]++;
            A /= x;
        }
    }
    if (A != 1LL) M[A] = 1;

    bool odd = (B % 2 == 1);
    mint ans = B, b = B;
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        ans *= b*(iter->second) + 1;
        if (iter->second % 2 == 1) odd = false;
    }

    if (odd) ans -= 1;
    ans /= 2;

    cout << ans.val() << endl;
}
