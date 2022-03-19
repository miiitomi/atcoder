// BIT+二分探索による解法.
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

bool less_than_k(BIT &bit, int k, int a) {
    return bit.sum(a) < k;
}

ll query(BIT &bit, int k) {
    int left = 0;
    int right = 200001;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (less_than_k(bit, k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    bit.add(left, -1);
    return left;
}

int main() {
    int Q;
    cin >> Q;

    BIT bit(200001);

    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            if (bit.sum(x, x + 1) == 0) bit.add(x, 1);
        } else {
            cout << query(bit, x) << endl;
        }
    }
}
