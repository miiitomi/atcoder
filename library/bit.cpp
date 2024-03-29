// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
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
    int N, Q;
    cin >> N >> Q;

    BIT bit(N);

    for (int q = 0; q < Q; q++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            x--;
            bit.add(x, y);
        } else {
            x--;
            y--;
            cout << bit.sum(x, y+1) << endl;
        }
    }
}
