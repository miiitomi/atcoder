#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

template<typename T> struct SegmentTree {
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

    void update(int i, T a) {
        // Update data[i] to a
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

    T query(int i, int j) {
        // Return the answer in [i, j)
        return _sub_query(i, j, 0, 0, n);
    }
};

template<typename X, typename M> struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = 0; // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return a+b;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return a+b;
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return x+m;
    }

    void initialize(int i, X x) {
        i = n - 1 + i;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = X_operation(data[i*2 + 1], data[i*2 + 2]);
        }
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

void solve() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        H[i]--;
    }
    SegmentTree<ll> st(N+1);
    LazySegmentTree<ll,ll> lst(N);
    for (int i = 0; i < N; i++) {
        ll l = st.query(H[i]+1, N+1);
        lst.update(l, i, 1);
        st.update(H[i], i);
    }
    for (int i = 0; i < N; i++) {
        cout << lst.query(i, i+1);
        if (i == N-1) cout << endl;
        else cout << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
