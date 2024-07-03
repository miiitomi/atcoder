// https://atcoder.jp/contests/abc351/tasks/abc351_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
struct SegmentTree {
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

    // Update data[i] to a.
    void update(int i, T a) {
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

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), v;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));

    ll M = v.size();
    SegmentTree<pair<ll,ll>> st(M);
    for (int i = 0; i < N; i++) {
        st.update(A[i], {v[A[i]], 1});
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        st.update(A[i], {-v[A[i]], -1});
        auto res = st.query(A[i]+1, M);
        ans += res.first - v[A[i]]*res.second;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
