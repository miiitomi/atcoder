#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<bool> is_prime(1e+7, true);
    vector<ll> primes;
    for (ll x = 2; x <= (int)1e+7; x++) {
        if (!is_prime[x]) continue;
        primes.push_back(x);
        for (ll y = 2*x; y <= (int)1e+7; y += x) {
            is_prime[y] = false;
        }
    }

    ll L, R;
    cin >> L >> R;
    vector<bool> is_true(R-L+1, true);
    ll ans = R-L+1;
    for (ll p: primes) {
        ll x = L+1 + (p - (L+1)%p)%p;
        for (; x <= R; x += p) {
            if (!is_true[x - L]) continue;
            ll y = x;
            while (y%p == 0) y /= p;
            if (y != 1) {
                is_true[x-L] = false;
                ans--;
            }
        }
    }
    cout << ans << "\n";
}
