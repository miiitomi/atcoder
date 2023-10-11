// https://atcoder.jp/contests/abc284/tasks/abc284_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primes;
vector<bool> is_prime;

void solve() {
    ll N;
    cin >> N;

    ll p, q;
    for (ll x : primes) {
        if (N % x == 0) {
            p = x;
            break;
        }
    }

    N /= p;
    if (N % p == 0) q = (N / p);
    else {
        q = p;
        ll left = 0, right = 3e+9 + 1;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid * mid <= N) left = mid;
            else right = mid;
        }
        p = left;
    }

    cout << p << " " << q << endl;
}


int main() {
    primes.reserve(1e+6);
    is_prime.assign(3*1e+6 + 1, true);
    for (int x = 2; x <= 3*1e+6; x++) {
        if (!is_prime[x]) continue;
        primes.push_back(x);
        for (int y = 2*x; y <= 3*1e+6; y += x) is_prime[y] = false;
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
