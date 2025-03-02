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

struct Query {
    ll R, X, ans, idx;
};

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> v, A(N);
    vector<Query> queries(Q);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    for (int i = 0; i < Q; i++) {
        int r, x;
        cin >> r >> x;
        r--;
        queries[i].idx = i;
        queries[i].R = r;
        queries[i].X = x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    for (int i = 0; i < Q; i++) {
        ll &x = queries[i].X;
        x = distance(v.begin(), lower_bound(v.begin(), v.end(), x));
    }
    sort(queries.begin(), queries.end(), [](const Query &l, const Query &r) {
        return l.R < r.R;
    });

    SegmentTree<ll> st(v.size());

    int idx = 0;
    for (Query &q: queries) {
        while (idx <= q.R) {
            int a = A[idx];
            st.update(a, st.query(0, a) + 1);
            idx++;
        }
        q.ans = st.query(0, q.X + 1);
    }
    sort(queries.begin(), queries.end(), [](const Query &l, const Query &r) {
        return l.idx < r.idx;
    });
    for (Query &q: queries) cout << q.ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
