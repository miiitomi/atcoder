// https://atcoder.jp/contests/abc070/tasks/abc070_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    __int128_t ans = 1;
    while (N--) {
        ll x;
        cin >> x;
        __int128_t y = x;
        ans = ans*x / gcd(ans, x);
    }

    cout << (ll)ans << endl;
}
