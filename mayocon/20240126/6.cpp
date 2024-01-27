// https://atcoder.jp/contests/abc215/tasks/abc215_f
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

template<typename T>
struct SegmentTreeMin {
    int n;
    vector<T> data;
    T init_value = 1e+9;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTreeMin(int _n) {
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

template<typename T>
struct SegmentTreeMax {
    int n;
    vector<T> data;
    T init_value = 0;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTreeMax(int _n) {
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
    vector<int> x(N), y(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        v[i] = x[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) x[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), x[i]));

    int M = v.size();

    SegmentTreeMin<int> stmin(M);
    SegmentTreeMax<int> stmax(M);
    for (int i = 0; i < N; i++) {
        stmin.update(x[i], y[i]);
        stmax.update(x[i], y[i]);
    }

    int left = 0, right = 1e+9 + 1;
    while (right - left > 1) {
        int m = (right + left) / 2;
        bool is_ok = false;
        for (int i = 0; i < N; i++) {
            int a = v[x[i]];
            auto iter = lower_bound(v.begin(), v.end(), a + m);
            if (iter != v.end()) {
                int b = distance(v.begin(), iter);
                if (stmin.query(b, M) <= y[i]-m || y[i]+m <= stmax.query(b, M)) is_ok = true;
            }
            auto iter2 = lower_bound(v.begin(), v.end(), a - m + 1);
            if (iter2 != v.begin()) {
                iter2--;
                int b = distance(v.begin(), iter2);
                if (stmin.query(0, b+1) <= y[i]-m || y[i]+m <= stmax.query(0, b+1)) is_ok = true;
            }
            if (is_ok) break;
        }
        if (is_ok) left = m;
        else right = m;
    }

    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
