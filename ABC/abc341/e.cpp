#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = true;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return a && b;
    }

    // Update data[i] to a.
    void update(int i) {
        i = n - 1 + i;
        data[i] = !data[i];  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        T vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        T vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    SegmentTree<bool> st(N-1);
    for (int i = 0; i < N-1; i++) if (S[i] == S[i+1]) st.update(i);

    while (Q--) {
        int k, l, r;
        cin >> k >> l >> r;
        l--;
        r--;
        if (k == 1) {
            if (l != 0) st.update(l-1);
            if (r != N-1) st.update(r);
        } else {
            bool res = true;
            if (r - l >= 1) res = st.query(l, r);
            if (res) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
