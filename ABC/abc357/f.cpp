#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

struct Data {
    ll size = 1;
    mint AB = 0;
    mint A = 0;
    mint B = 0;

    Data(ll s, mint ab, mint a, mint b) {
        size = s;
        AB = ab;
        A = a;
        B = b;
    }
};

template<typename X, typename M>
struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = Data(1, 0, 0, 0); // TODO: Set initial value of data X.
    M M_init = {0, 0}; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return Data(a.size + b.size, a.AB + b.AB, a.A + b.A, a.B + b.B);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return make_pair(a.first + b.first, a.second + b.second);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return Data(x.size, x.AB + (m.first*x.B) + (m.second*x.A) + (m.first * m.second * x.size), x.A + (m.first*x.size), x.B + (m.second*x.size));
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
    int N, Q;
    cin >> N >> Q;
    LazySegmentTree<Data, pair<mint,mint>> lst(N);
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) lst.update(i, i+1, make_pair(A[i], B[i]));

    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            lst.update(l, r, make_pair(x, 0));
        } else if (k == 2) {
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            lst.update(l, r, make_pair(0, x));
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            mint ans = lst.query(l, r).AB;
            cout << ans.val() << "\n";
        }
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
