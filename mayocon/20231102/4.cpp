// https://atcoder.jp/contests/abc300/tasks/abc300_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> is_prime(1000000, true);
vector<ll> primes;

int main() {
    for (int x = 2; x < 1000000; x++) {
        if (!is_prime[x]) continue;
        primes.push_back(x);
        for (int y = 2*x; y < 1000000; y += x) is_prime[y] = false;
    }


    ll N;
    cin >> N;
    ll ans = 0;

    for (int i = 0; i < primes.size(); i++) {
        for (int j = i+1; j < primes.size()-1; j++) {
            ll a = primes[i], b = primes[j];
            if (a * b * b >= N) break;
            ll l = 1;
            ll r = round(sqrt(N / (a*a*b))) + 2;

            while (r - l > 1) {
                ll m = (l + r) / 2;
                if (a*a*b*m*m > N) r = m;
                else l = m;
            }

            int k =  distance(primes.begin(), lower_bound(primes.begin(), primes.end(), l+1)) - 1;
            if (k > j) ans += k - j;
            else break;
        }
    }

    cout << ans << endl;
}
