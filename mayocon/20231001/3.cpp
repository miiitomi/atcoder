// https://atcoder.jp/contests/abc169/tasks/abc169_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    map<ll, ll> primes;
    for (ll x = 2; x*x <= N; x++) {
        if (N % x == 0) primes[x] = 0;
        while (N % x == 0) {
            primes[x]++;
            N /= x;
        }
    }
    if (N != 1) primes[N] = 1;

    ll ans = 0;
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        ll x = iter->first;
        int i = 1;
        while (primes[x] >= i) {
            primes[x] -= i;
            i++;
            ans++;
        }
    }
    cout << ans << endl;
}
