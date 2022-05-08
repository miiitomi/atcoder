#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    vector<bool> is_prime(1000001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int x = 2; x < 1000001; x++) {
        if (is_prime[x]) {
            for (int y = 2*x; y < 1000001; y += x) {
                is_prime[y] = false;
            }
        }
    }
    vector<ll> V;
    for (int x = 2; x < 1000001; x++) {
        if (is_prime[x]) {
            V.push_back(x);
        }
    }

    ll ans = 0;
    for (int idx_p = 0; idx_p < V.size(); idx_p++) {
        ll p = V[idx_p];
        ll X = N / p;
        int left = idx_p;
        int right = V.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            ll q = V[mid];
            if (q * q * q <= X) {
                left = mid;
            } else {
                right = mid;
            }
        }
        ans += left - idx_p;
        if (left - idx_p == 0) break;
    }

    cout << ans << endl;
}
