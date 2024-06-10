// https://atcoder.jp/contests/abc309/tasks/abc309_f
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = 1e+9;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return min(a, b);
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
    int N;
    cin >> N;
    vector<vector<int>> X(N, vector<int>(3, 0));
    vector<int> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> X[i][j];
            v.push_back(X[i][j]);
        }
        sort(X[i].begin(), X[i].end());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            X[i][j] = distance(v.begin(), lower_bound(v.begin(), v.end(), X[i][j]));
        }
    }

    int M = v.size();
    sort(X.begin(), X.end(), [](vector<int> &l, vector<int> &r) {if (l[0] != r[0]) return l[0] < r[0]; else return l[1] > r[1];});
    SegmentTree<int> st(M);

    for (vector<int> &x : X) {
        int res = st.query(0, x[1]);
        if (res < x[2]) {
            cout << "Yes\n";
            return;
        }
        st.update(x[1], x[2]);
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
