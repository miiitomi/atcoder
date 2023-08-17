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



void solve() {
    int N;
    cin >> N;
    BIT bit(N);
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        B[i] = bit.sum(0, A[i]);
        bit.add(A[i], 1);
    }

    BIT bit2(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] > 0 && bit2.sum(0, A[i]) == 0) ans++;
        bit2.add(A[i], B[i]);
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
