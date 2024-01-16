// https://atcoder.jp/contests/abc170/tasks/abc170_e
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = 2e+9;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

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
    int N, Q, M = (int)2e+5;
    cin >> N >> Q;
    vector<int> youchien(N), rate(N);
    vector<multiset<int>> S(M);
    for (int i = 0; i < N; i++) {
        cin >>  rate[i] >> youchien[i];
        youchien[i]--;
        S[youchien[i]].insert(rate[i]);
    }
    SegmentTree<int> st(M);
    for (int j = 0; j < M; j++) if (!S[j].empty()) st.update(j, *S[j].rbegin());

    while (Q--) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        int y = youchien[c];
        S[y].erase(S[y].find(rate[c]));
        if (S[y].empty()) st.update(y, (int)2e+9);
        else st.update(y, *S[y].rbegin());

        youchien[c] = d;
        S[d].insert(rate[c]);
        st.update(d, *S[d].rbegin());

        cout << st.query(0, M) << "\n";
    }
}
