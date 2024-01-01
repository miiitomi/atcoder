// https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>
using namespace std;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = false; // TODO: Set initial value of data X.
    M M_init = false; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return a || b;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a || b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return x || m;
    }

    void eval(int k) {
        if (lazy[k] == M_init) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = M_operation(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = M_operation(lazy[k * 2 + 2], lazy[k]);
        }
        data[k] = X_M_operation(data[k], lazy[k]);
        lazy[k] = M_init;
    }

    void _update(int a, int b, M m, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {
            lazy[k] = M_operation(lazy[k], m);
            eval(k);
        } else if (a < r && l < b) {
            _update(a, b, m, k * 2 + 1, l, (l + r) / 2);
            _update(a, b, m, k * 2 + 2, (l + r) / 2, r);
            data[k] = X_operation(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // Update data[i] with i in [a, b) by multiplying m in M.
    void update(int a, int b, M m) {
        _update(a, b, m, 0, 0, n);
    }

    X _sub_query(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {
            return X_init;
        } else if (a <= l && r <= b) {
            return data[k];
        } else {
            X vl = _sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = _sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return X_operation(vl, vr);
        }
    }

    // Return the answer in [a, b)
    X query(int a, int b) {
        return _sub_query(a, b, 0, 0, n);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> c(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        c[A[i]].push_back(i);
    }

    vector<int> B(N);
    vector<int> d(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        B[i]--;
        d[B[i]]++;
    }

    for (int x = 0; x < N; x++) {
        if (d[x] + c[x].size() > N) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    LazySegmentTree<bool, bool> lst(N);
    for (int i = 0; i < N; i++) {
        int x = B[i];
        if (c[x].empty()) continue;
        int l = c[x][0], r = c[x].back();
        if (0 <= r-i ) lst.update(max(0, l-i), r-i+1, true);
        l += N;
        r += N;
        if (l - i < N) lst.update(l-i, min(N, r-i+1), true);
    }

    int k = 0;
    for (int s = 0; s < N; s++) {
        if (!lst.query(s, s+1)) {
            k = s;
            break;
        }
    }
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        ans[(i + k) % N] = B[i];
    }

    for (int a : ans) cout << a+1 << " ";
    cout << endl;
}
