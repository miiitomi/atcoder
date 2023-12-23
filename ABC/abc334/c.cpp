#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(K);
    for (int i = 0; i < K; i++) cin >> A[i];

    if (K % 2 == 0) {
        ll ans = 0;
        for (int i = 0; i+1 < K; i += 2) ans += abs(A[i+1]-A[i]);
        cout << ans << endl;
        return 0;
    }

    BIT b1(K+1), b2(K+1);
    for (int i = 1; i < K; i += 2) {
        b1.add(i, abs(A[i] - A[i-1]));
    }
    for (int i = K-2; i >= 0; i -= 2) {
        b2.add(i, abs(A[i] - A[i+1]));
    }

    ll ans = 1e+18;
    for (int i = 0; i < K; i += 2) {
        ans = min(ans, b1.sum(0, i) + b2.sum(i+1, K));
    }
    cout << ans << endl;
}
