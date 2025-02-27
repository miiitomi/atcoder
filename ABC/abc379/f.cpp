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
    ll idx, l, r, ans;
    Query(ll i, ll _l, ll _r) {
        idx = i;
        l = _l;
        r = _r;
    }
};


void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> H(N);
    SegmentTree<ll> st(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
        st.update(i, H[i]);
    }
    vector<Query> Queries;
    for (int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;
        l--; r--;
        Queries.push_back(Query(q, l, r));
    }
    sort(Queries.begin(), Queries.end(), [](const Query &l, const Query &r) {return l.r > r.r;});
    deque<ll> D;
    ll r = N-1;
    for (auto &q : Queries) {
        while (q.r < r) {
            ll h = H[r];
            while (!D.empty() && D.front() < h) D.pop_front();
            D.push_front(h);
            r--;
        }
        ll h = st.query(q.l+1, q.r+1);
        auto iter = lower_bound(D.begin(), D.end(), h);
        q.ans = (ll)distance(iter, D.end());
    }
    sort(Queries.begin(), Queries.end(), [](const Query &l, const Query &r) {return l.idx < r.idx;});
    for (auto &q : Queries) {
        cout << q.ans << "\n";
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
