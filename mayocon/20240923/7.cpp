// https://atcoder.jp/contests/abc211/tasks/abc211_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

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

struct Query {
    ll idx, x, y, ans;
    Query(ll i, ll _x, ll _y) {
        idx = i;
        x = _x;
        y = _y;
    }
};

void solve() {
    ll N;
    cin >> N;
    vector<pair<ll, pair<ll,ll>>> A, B;
    LazySegmentTree<ll, ll> lst((int)1e+5 + 2);
    for (int i = 0; i < N; i++) {
        ll M;
        cin >> M;
        vector<pair<ll, pair<ll,ll>>> E;
        for (int i = 0; i < M; i += 2) {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            E.push_back({x1, {min(y1,y2), max(y1,y2)}});
        }
        sort(E.begin(), E.end());
        for (auto &e : E) {
            int y1 = e.second.first, y2 = e.second.second;
            if (lst.query(y1, y1+1) == 0) {
                lst.update(y1, y2, 1);
                A.push_back(e);
            } else {
                lst.update(y1, y2, -1);
                B.push_back(e);
            }
        }
    }
    ll Q;
    cin >> Q;
    vector<Query> V;
    for (int i = 0; i < Q; i++) {
        ll x, y;
        cin >> x >> y;
        V.push_back(Query(i, x, y));
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {if (l.x != r.x) return l.x < r.x; return l.y < r.y;});
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for (auto &v : V) {
        while (!B.empty() && B.back().first <= v.x) {
            lst.update(B.back().second.first, B.back().second.second, -1);
            B.pop_back();
        }
        while (!A.empty() && A.back().first <= v.x) {
            lst.update(A.back().second.first, A.back().second.second, 1);
            A.pop_back();
        }
        v.ans = lst.query(v.y, v.y+1);
    }
    sort(V.begin(), V.end(), [](const Query &l, const Query &r) {return l.idx < r.idx;});
    for (auto &v : V) cout << v.ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
