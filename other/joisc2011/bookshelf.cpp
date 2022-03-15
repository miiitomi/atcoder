#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    int n;
    vector<ll> data;

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, 0);
    }

    void update(int i, ll a) {
        i = n - 1 + i;
        data[i] = a;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = max(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    ll query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return 0;
        if (i <= l && r <= j) return data[k];
        ll vl = query(i, j, 2*k + 1, l, (l + r)/2);
        ll vr = query(i, j, 2*k + 2, (l + r)/2, r);
        return max(vl, vr);
    }

    ll query(int i, int j) {
        return query(i, j, 0, 0, n);
    }
};

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
    }

    SegmentTree st(N);
    for (int i = 0; i < N; i++) {
        int j = B[i];
        ll a = st.query(0, j) + A[j];
        st.update(j, a);
    }

    cout << 2 * (sum - st.query(0, N)) << endl;
}
