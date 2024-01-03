// https://atcoder.jp/contests/abc221/tasks/abc221_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = 0; // TODO: Set initial value of data X.
    M M_init = make_pair(1, 0); // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return (a+b) % MOD;
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return make_pair(a.first*b.first % MOD, (b.first*a.second + b.second) % MOD);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return (m.first*x + m.second) % MOD;
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<ll> v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < N; i++) {
        A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));
    }

    LazySegmentTree<ll, pair<ll,ll>> lst(N);
    lst.update(0, A.back()+1, make_pair(1, 1));
    A.pop_back();
    ll ans = 0;
    while (!A.empty()) {
        ans += lst.query(A.back(), A.back()+1);
        ans %= MOD;
        lst.update(0, N, make_pair(2, 0));
        lst.update(0, A.back()+1, make_pair(1, 1));
        A.pop_back();
    }
    cout << ans << endl;
}
