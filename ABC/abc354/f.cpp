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

int lis_left(int N, vector<int> &A, vector<int> &res) {
    res.assign(N, 0);
    int M = *max_element(A.begin(), A.end()) + 1;
    SegmentTree<int> st(M);
    for (int i = 0; i < N; i++) {
        int x = st.query(0, A[i]);
        res[i] = x+1;
        st.update(A[i], x+1);
    }
    return st.query(0, M);
}

int lis_right(int N, vector<int> &A, vector<int> &res) {
    res.assign(N, 0);
    int M = *max_element(A.begin(), A.end()) + 1;
    SegmentTree<int> st(M);
    for (int i = N-1; i >= 0; i--) {
        int x = st.query(A[i]+1, M);
        res[i] = x+1;
        st.update(A[i], x+1);
    }
    return st.query(0, M);
}


void solve() {
    int N;
    cin >> N;
    vector<int> A(N), v;
    for (int i = 0; i < N; i++) cin >> A[i];
    v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));

    vector<int> left, right;
    int L = lis_left(N, A, left);
    lis_right(N, A, right);

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (left[i] + right[i] == L+1) {
            ans.push_back(i+1);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T;
    cin >> T;
    while (T--) solve();
}
