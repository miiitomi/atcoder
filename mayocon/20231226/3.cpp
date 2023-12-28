// https://atcoder.jp/contests/abc238/tasks/abc238_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
    ll n;
    cin >> n;
    __int128_t N = n, ans = 0;
    ans = ((N * (N+1)) / 2LL) % MOD;
    for (__int128_t l = 1; l <= N; l *= 10) {
        __int128_t r = min(10 * l -1, N);
        __int128_t x = l-1;
        ans -= (r-l+1)*x % MOD;
        while (ans < 0) ans += MOD;
    }
    cout << (ll)ans << endl;
}
