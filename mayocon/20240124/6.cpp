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
    vector<vector<int>> V(N, vector<int>(3));
    vector<int> p;
    for (int i = 0; i < N; i++) {
        cin >> V[i][0] >> V[i][1] >> V[i][2];
        sort(V[i].begin(), V[i].end());
        for (int x : V[i]) p.push_back(x);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) V[i][j] = 1 + distance(p.begin(), lower_bound(p.begin(), p.end(), V[i][j]));
    sort(V.begin(), V.end(), [](const vector<int> &l, const vector<int> &r) {
        if (l[0] != r[0]) return l[0] < r[0];
        else return l > r;
    });

    SegmentTree<int> st(1 + p.size());
    for (vector<int> &v : V) {
        if (st.query(0, v[1]) < v[2]) {
            cout << "Yes" << endl;
            return;
        }
        st.update(v[1], v[2]);
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
