#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primes;
vector<bool> is_prime(1e+4, true);

void solve() {
    ll l, r;
    cin >> l >> r;
    if (r <= 3) {
        cout << -1 << endl;
        return;
    }
    if (l != r || r % 2 == 0) {
        while (r % 2 == 1) r--;
        cout << r/2 << " " << r/2 << endl;
        return;
    }

    for (ll x : primes) {
        if (l == x) break;
        if (l % x == 0) {
            cout << l / x << " " << (l / x) * (x-1) << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    primes.reserve(1e+4);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int x = 2; x < 1e+4; x++) {
        if (is_prime[x]) {
            primes.push_back(x);
            for (int y = 2*x; y < 1e+4; y += x) is_prime[y] = false;
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
