// https://atcoder.jp/contests/abc300/tasks/abc300_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<bool> is_prime(1000000, true);
    vector<ll> primes;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int x = 2; x < 1000000; x++) {
        if (is_prime[x]) {
            primes.push_back(x);
            for (int y = 2*x; y < 1000000; y += x) is_prime[y] = false;
        }
    }

    set<ll> S;
    for (int i = 0; i < (int)primes.size(); i++) {
        ll a = primes[i];
        if (a * a * a * a >= N) break;
        for (int j = i+1; j < (int)primes.size(); j++) {
            ll b = primes[j];
            if (a * a * b * b * b >= N) break;
            for (int k = j+1; k < (int)primes.size(); k++) {
                ll c = primes[k];
                if (a * a * b * c * c <= N) S.insert(a * a * b * c * c);
                else break;
            }
        }
    }

    cout << S.size() << endl;
}
