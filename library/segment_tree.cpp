// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 2147483647;

struct SegmentTree {
    int n;
    vector<ll> data;

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, INF);
    }

    void update(int i, ll a) {
        i = n - 1 + i;
        data[i] = a;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = min(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    ll query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return INF;
        if (i <= l && r <= j) return data[k];
        ll vl = query(i, j, 2*k + 1, l, (l + r)/2);
        ll vr = query(i, j, 2*k + 2, (l + r)/2, r);
        return min(vl, vr);
    }

    ll query(int i, int j) {
        return query(i, j, 0, 0, n);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) st.update(x, y);
        else cout << st.query(x, y+1) << endl;
    }
}
