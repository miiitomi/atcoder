// https://atcoder.jp/contests/abc309/tasks/abc309_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        ll vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        ll vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int N;
vector<vector<int>> V;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
}

int main() {
    cin >> N;
    V.assign(N, vector<int>(3));
    vector<int> v;
    v.reserve(3*N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> V[i][j];
            v.push_back(V[i][j]);
        }
        sort(V[i].begin(), V[i].end());
    }
    sort(V.begin(), V.end(), cmp);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            V[i][j] = distance(v.begin(), lower_bound(v.begin(), v.end(), V[i][j]));
        }
    }

    SegmentTree<int> st((int)v.size());

    for (auto &w : V) {
        int b = w[1], c = w[2];
        if (st.query(0, b) < c) {
            cout << "Yes" << endl;
            return 0;
        }
        st.update(b, c);
    }

    cout << "No" << endl;
}
