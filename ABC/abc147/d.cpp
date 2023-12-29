#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

struct BIT {
    int n;
    vector<ll> data;

    BIT(int _n) {
        n = _n + 1;
        data.assign(n, 0);
    }

    void add(int i, ll x) {
        // Add x to a[i] (0-indexed).
        for (int idx = i + 1; idx < n; idx += (idx & -idx)) {
            data[idx] += x;
        }
    }

    ll sum(int i) {
        // compute sum of a[i] with i in [0, i)
        ll ans = 0;
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            ans += data[idx];
        }
        return ans;
    }

    ll sum(int a, int b) {
        // compute sum of a[i] with i in [a, b)
        return sum(b) - sum(a);
    }
};

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;

    for (ll k = 0; k < 60; k++) {
        ll x = (1LL << k) % MOD;
        BIT bit(N);
        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << k)) bit.add(i, 1);
        }

        for (int i = 0; i < N-1; i++) {
            ll cnt = bit.sum(i+1, N);
            if (A[i] & (1LL << k)) cnt = N-1-i - cnt;
            ans = (ans + cnt*x%MOD) % MOD;
        }
    }

    cout << ans << endl;
}
