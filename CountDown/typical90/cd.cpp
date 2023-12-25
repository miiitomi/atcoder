#include <bits/stdc++.h>
using namespace std;
using ill = long long;
typedef __int128_t ll;
const ll MOD = 1e+9 + 7;

ll f(ll N) {
    ll k = 0, ans = 0;
    for (ll l = 1; l <= N; l *= 10) {
        k++;
        ll r = min(10*l-1, N);
        ans += ((l + r) * (r - l + 1) / 2) % MOD * k % MOD;
    }
    return ans;
}

int main() {
    ill L, R;
    cin >> L >> R;
    ll l = L, r = R;
    cout << (ill)((f(r) - f(l-1) + MOD) % MOD) << endl;
}
