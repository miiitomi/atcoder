#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll modpow(ll x, ll n) {
    if (n == 0) return 1LL;
    else {
        ll res = modpow(x, n/2);
        res = res * res % MOD;
        if (n % 2 == 1) res = res * x % MOD;
        return res;
    }
}

ll modinv(ll a) {
    return modpow(a, MOD-2);
}

template <typename T>
struct BIT {
    int n;
    vector<T> data;

    BIT(int n_) {
        n = n_ + 1;
        data.assign(n, 0);
    }

    void add(int x, T a) {
        for (int i = x + 1; i < n; i += (i & -i)) {
            data[i] += a;
            data[i] %= MOD;
        }
    }

    T sum(int x) {
        T s = 0;
        for (int i = x + 1; i > 0; i -= (i & -i)) {
            s += data[i];
            s %= MOD;
        }
        return s;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        V[i].first = A[i];
        V[i].second = i;
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++) A[V[i].second] = i;

    vector<ll> B(N, 0);
    BIT<ll> bit(N);
    for (int i = 0; i < N; i++) {
        B[i] = bit.sum(A[i]);
        bit.add(A[i], modinv(modpow(2, i)));
    }
    ll ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans += (B[i] * modpow(2, i-1));
        ans %= MOD;
    }
    cout << ans << endl;
}
