// https://atcoder.jp/contests/abc296/tasks/abc296_f
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
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    multiset<int> _A, _B;
    for (int a : A) _A.insert(a);
    for (int b : B) _B.insert(b);

    if (_A != _B) {
        cout << "No" << endl;
        return 0;
    }

    for (int a : A) if ((int)_A.count(a) != 1) {
        cout << "Yes" << endl;
        return 0;
    }

    ll inverse_a = 0, inverse_b = 0;
    BIT bit_a(N+1), bit_b(N+1);
    for (int i = 0; i < N; i++) {
        inverse_a += bit_a.sum(0, A[i]);
        bit_a.add(A[i], 1);
        inverse_b += bit_b.sum(0, B[i]);
        bit_b.add(B[i], 1);
    }

    if (inverse_a % 2 == inverse_b % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
