// https://atcoder.jp/contests/abc309/tasks/abc309_f
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
        data[i] = operation(data[i], a);
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


bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0]) return a[0] > b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}


int main() {
    int N;
    cin >> N;
    vector<vector<int>> B(N, vector<int>(3));
    vector<int> v;
    v.reserve(3*N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
            v.push_back(B[i][j]);
        }
        sort(B[i].begin(), B[i].end());
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            B[i][j] = 1 + distance(v.begin(), lower_bound(v.begin(), v.end(), B[i][j]));
        }
    }

    sort(B.begin(), B.end(), cmp);

    SegmentTree<int> st((int)v.size()+3);
    for (vector<int> &b : B) {
        if (b[2] < st.query(b[1]+1, v.size()+3)) {
            cout << "Yes" << endl;
            return 0;
        }
        st.update(b[1], b[2]);
    }

    cout << "No" << endl;
}
