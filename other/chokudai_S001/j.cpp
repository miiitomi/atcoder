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
    ll N;
    cin >> N;
    vector<ll> A(N), B;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        B.push_back(a);
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    for (int i = 0; i < N; i++) {
        ll a = A[i];
        auto iter = lower_bound(B.begin(), B.end(), a);
        A[i] = distance(B.begin(), iter);
    }

    int M = *max_element(A.begin(), A.end()) + 1;
    BIT bit(M);
    ll ans = (N * (N-1)) / 2;
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        ll s = bit.sum(a);
        ans -= s;
        bit.add(a, 1);
    }

    cout << ans << endl;
}
