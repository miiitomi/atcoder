// https://atcoder.jp/contests/abc255/tasks/abc255_h
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = make_pair(0, 0); // TODO: Set initial value of data X.
    M M_init = 0; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return make_pair(a.first+b.first, a.second+b.second);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return max(a, b);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return make_pair(x.first, x.first * m);
    }

    void initialize(int i, X a) {
        i = n - 1 + i;
        data[i] = a;
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> D(Q), L(Q), R(Q), v;
    for (int i = 0; i < Q; i++) {
        cin >> D[i] >> L[i] >> R[i];
        L[i]--;
        v.push_back(L[i]);
        v.push_back(R[i]);
    }
    v.push_back(N);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < Q; i++) {
        L[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), L[i]));
        R[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), R[i]));
    }

    ll M = v.size();
    LazySegmentTree<pair<mint,mint>, ll> lst(M-1);
    for (int i = 0; i < M-1; i++) {
        mint l = (v[i] + 1) % 998244353;
        mint r = v[i+1] % 998244353;
        mint x = ((r+l)*(r-l+1))/2;
        lst.initialize(i, {x, 0});
    }

    for (int q = 0; q < Q; q++) {
        pair<mint,mint> res = lst.query(L[q], R[q]);
        mint ans = res.first * D[q] - res.second;
        lst.update(L[q], R[q], D[q]);
        cout << ans.val() << endl;
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
