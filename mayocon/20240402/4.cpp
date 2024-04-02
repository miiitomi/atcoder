// https://atcoder.jp/contests/abc172/tasks/abc172_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> primes;

void solve() {
    int N;
    cin >> N;
    ll ans = 1;
    for (int x = 2; x <= N; x++) {
        int y = x;
        ll cnt = 1;
        for (int p : primes) {
            if (p*p > y) {
                if (y != 1) cnt *= 2;
                break;
            }
            ll tmp = 1;
            while (y % p == 0) {
                tmp++;
                y /= p;
            }
            cnt *= tmp;
        }
        ans += x * cnt;
    }
    cout << ans << "\n";
}

int main() {
    vector<bool> is_prime(1e+4, true);
    for (int x = 2; x < 1e+4; x++) {
        if (is_prime[x]) {
            primes.push_back(x);
            for (int y = 2*x; y < 1e+4; y += x) is_prime[y] = false;
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
