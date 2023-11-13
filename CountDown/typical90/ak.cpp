#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = -1;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return max(a, b);
    }

    // Update data[i] to a.
    void update(int i, T a) {
        i = n - 1 + i;
        data[i] = operation(data[i], a);  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        ll vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        ll vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int main() {
    ll W, N;
    cin >> W >> N;
    SegmentTree<ll> st(W+2);
    st.update(0, 0);

    for (int i = 0; i < N; i++) {
        ll l, r, v;
        cin >> l >> r >> v;
        for (ll w = W; w >= 0; w--) {
            if (w - l < 0) continue;
            ll s = st.query(max(w-r, 0LL), w-l+1);
            if (s >= 0) st.update(w, s + v);
        }
    }

    cout << st.query(W, W+1) << endl;
}
