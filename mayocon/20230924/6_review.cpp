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

    vector<int> sorted_A = A, sorted_B = B;
    sort(sorted_A.begin(), sorted_A.end());
    sort(sorted_B.begin(), sorted_B.end());

    if (sorted_A != sorted_B) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> C(N);
    for (int i = 0; i < N; i++) C[i] = i+1;
    if (sorted_A != C) {
        cout << "Yes" << endl;
        return 0;
    }

    ll na = 0, nb = 0;
    BIT bit_a(N), bit_b(N);
    for (int i = 0; i < N; i++) {
        int a = A[i]-1, b = B[i]-1;
        na += bit_a.sum(0, a);
        nb += bit_b.sum(0, b);
        bit_a.add(a, 1);
        bit_b.add(b, 1);
    }

    if (na % 2 == nb % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
