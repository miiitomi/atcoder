#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = 0;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

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
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    T _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        int vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        int vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    SegmentTree<int> st1(N+2), st2(N+2);
    vector<int> X(N, 0), Y(N, 0), Z(N, 0);

    for (int i = 0; i < N; i++) {
        X[i] = 1 + st1.query(0, A[i]);
        st1.update(A[i], X[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        Y[i] = 1 + st2.query(0, A[i]);
        st2.update(A[i], Y[i]);
        Z[i] = Y[i] + X[i] - 1;
    }

    cout << *max_element(Z.begin(), Z.end()) << endl;
}
