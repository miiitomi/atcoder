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
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    BIT bit(N);
    int ans = 0;
    for (int i = N-1; i >= 0; i--) {
        int p = P[i];
        if (bit.sum(0, p) == 0) ans++;
        bit.add(p, 1);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
}
