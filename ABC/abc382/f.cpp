#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll H, W, N;

template<typename X, typename M> struct LazySegmentTree {
    int n;
    vector<X> data;
    vector<M> lazy;
    X X_init = H; // TODO: Set initial value of data X.
    M M_init = H; // TODO: Set initial value of act M.

    LazySegmentTree(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, X_init);
        lazy.assign(2*n-1, M_init);
    }

    X X_operation(X a, X b) {
        // TODO: Set operation on X x X. (e.g., min, max, +)
        return min(a, b);
    }

    M M_operation(M a, M b) {
        // TODO: Set operation on M x M.
        return min(a, b);
    }

    X X_M_operation(X x, M m) {
        // TODO: Set operation on X x M
        return min(x, m);
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

struct Bar {
    ll i, r, c, l, ans;
    Bar(ll _i, ll _r, ll _c, ll _l) {
        i = _i;
        r = _r;
        c = _c;
        l = _l;
    }
};

void solve() {
    cin >> H >> W >> N;
    vector<Bar> V;
    for (int i = 0; i < N; i++) {
        ll r, c, l;
        cin >> r >> c >> l;
        r--; c--;
        V.push_back(Bar(i, r, c, l));
    }
    sort(V.begin(), V.end(), [](const Bar &left, const Bar &right) {return left.r > right.r;});
    LazySegmentTree<ll, ll> lst(W);
    for (Bar &bar : V) {
        ll res = lst.query(bar.c, bar.c+bar.l);
        bar.ans = res - 1;
        lst.update(bar.c, bar.c + bar.l, bar.ans);
    }
    sort(V.begin(), V.end(), [](const Bar &left, const Bar &right) {return left.i < right.i;});
    for (Bar &bar : V) {
        cout << bar.ans + 1 << "\n";
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
