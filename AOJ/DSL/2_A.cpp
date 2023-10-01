// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 2147483647;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = INF;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T compare(T a, T b) {
        // TODO: Set compareing function (e.g., min, max, sum)
        return min(a, b);
    }

    // Update data[i] to a.
    void update(int i, T a) {
        i = n - 1 + i;
        data[i] = a;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = compare(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        ll vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        ll vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return compare(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};


int main() {
    int n, q;
    cin >> n >> q;

    SegmentTree<ll> st(n);

    for (int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) st.update(x, y);
        else cout << st.query(x, y+1) << endl;
    }
}
