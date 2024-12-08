#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<bool> is_prime(2e+6 + 1, true);
vector<ll> primes;

void solve() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < (int)primes.size(); i++) {
        ll a = primes[i];
        if (a*a >= N) break;
        ll left = -1, right = primes.size();
        while (right - left > 1) {
            ll m = (left + right) / 2;
            ll tmp = a*a*primes[m];
            bool ok = (tmp < N);
            if (ok) tmp *= primes[m];
            if (tmp <= N) {
                left = m;
            } else {
                right = m;
            }
        }
        if (left <= i) break;
        ans += left - i;
    }
    for (ll a : primes) {
        ll x = 1;
        for (int k = 0; k < 8; k++) {
            x *= a;
            if (x > N) break;
        }
        if (x > N) break;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    for (int x = 2; x <= (int)2e+6; x++) {
        if (!is_prime[x]) continue;
        primes.push_back(x);
        for (ll y = 2*x; y <= (int)2e+6; y += x) is_prime[y] = false;
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
