// https://atcoder.jp/contests/abc343/tasks/abc343_f
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
    T init_value = vector<pair<ll,ll>>(2, {0, 0});  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        vector<int> v;
        for (int k = 0; k < 2; k++) {
            v.push_back(a[k].first);
            v.push_back(b[k].first);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        reverse(v.begin(), v.end());
        while (v.size() > 2) v.pop_back();
        vector<pair<ll,ll>> c(v.size(), {0,0});
        for (int i = 0; i < (int)v.size(); i++) {
            c[i].first = v[i];
            for (int k = 0; k < 2; k++) {
                c[i].second += (a[k].first == v[i])*a[k].second;
                c[i].second += (b[k].first == v[i])*b[k].second;
            }
        }
        return c;
    }

    void update(int i, ll a) {
        // Update data[i] to a
        i = n - 1 + i;
        data[i] = {{a, 1}, {0, 0}};  // TODO: Set update operation if needed (e.g. data[i] = a )
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
    int N, Q;
    cin >> N >> Q;
    SegmentTree<vector<pair<ll,ll>>> st(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        st.update(i, a);
    }
    while (Q--) {
        ll k, l, r;
        cin >> k >> l >> r;
        if (k == 1) {
            l--;
            st.update(l, r);
        } else {
            l--;
            cout << st.query(l, r)[1].second << "\n";
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
