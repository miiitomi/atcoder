#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> prime_factorization(ll N) {
    // Assume N >= 2.

    ll n = 1;
    while (n*n < N) n++;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll x = 2; x <= n; x++) {
        if (!is_prime[x]) continue;
        for (ll y = 2*x; y <= n; y += x) is_prime[y] = false;
    }

    map<ll, ll> M;
    for (ll x = 2; x <= n; x++) {
        if (!is_prime[x]) continue;
        while (N % x == 0) {
            M[x]++;
            N /= x;
        }
    }

    if (N != 1) M[N]++;

    return M;
}

int main() {
    ll N;
    cin >> N;
    map<ll, ll> M = prime_factorization(N);

    cout << N << ":";
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        for (int i = 0; i < iter->second; i++) {
            cout << " " << iter->first ;
        }
    }
    cout << endl;
}
