// https://atcoder.jp/contests/abc299/tasks/abc299_g
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

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

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return min(a, b);
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
        T vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        T vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> I(M);

    SegmentTree<int> st1(N+1), st2(M+1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        st1.update(i, A[i]);
        st2.update(A[i], i);
        I[A[i]].push_back(i);
    }

    vector<int> ans;
    int i = 0;
    for (int k = 0; k < M; k++) {
        int j = st2.query(0, M);
        int a = st1.query(i, j+1);
        ans.push_back(a);
        for (int l : I[a]) st1.update(l, INF);
        st2.update(a, INF);
        i = *lower_bound(I[a].begin(), I[a].end(), i) + 1;
    }

    for (int a : ans) cout << a+1 << " ";
    cout << endl;
}
