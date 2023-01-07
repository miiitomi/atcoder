#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll M = 3 * (1e+6);
    vector<ll> is_prime(M + 1, true);
    vector<ll> P;

    is_prime[0] = false;
    is_prime[1] = false;

    for (ll i = 2; i <= M; i++) {
        if (is_prime[i]) {
            P.push_back(i);
            for (ll j = 2*i; j <= M; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int T;
    cin >> T;

    int num_p = (int)P.size();

    for (int t = 0; t < T; t++) {
        ll N;
        cin >> N;

        ll p, q;

        for (ll x : P) {
            if (N % x == 0) {
                p = x;
                break;
            }
        }

        N /= p;
        if (N % p == 0) {
            q = N / p;
        } else {
            q = p;

            ll p_left = 1;
            ll p_right = 3LL * ((ll)(1e+9));

            while (p_right - p_left > 1) {
                ll mid = (p_left + p_right) / 2LL;
                if (mid*mid > N) {
                    p_right = mid;
                } else {
                    p_left = mid;
                }
            }

            p = p_left;
        }

        cout << p << " " << q << endl;
    }
}
