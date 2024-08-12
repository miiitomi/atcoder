// https://atcoder.jp/contests/abc287/tasks/abc287_g
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
    T init_value = {0, 0};  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return {a.first+b.first, a.second+b.second};
    }

    void update(int i, T a) {
        // Update data[i] to a
        i = n - 1 + i;
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
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

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N), v;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        v.push_back(a[i]);
    }
    ll Q;
    cin >> Q;
    vector<ll> t(Q), x(Q), y(Q);
    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> x[i];
        if (t[i] != 3) {
            x[i]--;
            cin >> y[i];
            if (t[i] == 1) v.push_back(y[i]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll M = v.size();
    SegmentTree<pair<ll,ll>> st(M);
    for (int i = 0; i < N; i++) {
        a[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), a[i]));
        ll s = st.query(a[i], a[i]+1).first;
        s += b[i];
        st.update(a[i], {s, v[a[i]]*s});
    }
    for (int q = 0; q < Q; q++) {
        if (t[q] == 1) {
            ll w = a[x[q]];
            ll s = st.query(w, w+1).first;
            s -= b[x[q]];
            st.update(w, {s, s*v[w]});
            w = distance(v.begin(), lower_bound(v.begin(), v.end(), y[q]));
            a[x[q]] = w;
            s = st.query(w, w+1).first;
            s += b[x[q]];
            st.update(w, {s, s*v[w]});
        } else if (t[q] == 2) {
            ll w = a[x[q]];
            ll s = st.query(w, w+1).first;
            s += y[q] - b[x[q]];
            st.update(w, {s, s*v[w]});
            b[x[q]] = y[q];
        } else {
            if (st.query(0, M).first < x[q]) {
                cout << -1 << "\n";
                continue;
            }
            ll left = 0, right = M;
            while (right - left > 1) {
                ll m = (left + right) / 2;
                if (st.query(m, M).first >= x[q]) left = m;
                else right = m;
            }
            auto res = st.query(left, M);
            ll ans = res.second - (res.first - x[q])*v[left];
            cout << ans << "\n";
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
