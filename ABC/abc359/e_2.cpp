#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e+18;

template<typename T>
struct SegmentTree {
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
    vector<ll> H(N+1, INF), v;
    v.push_back(INF);
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        v.push_back(H[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (ll &h : H) h = distance(v.begin(), lower_bound(v.begin(), v.end(), h));
    int M = v.size();
    SegmentTree<ll> st(M);
    vector<ll> ans(N+1, 0);

    for (int i = 1; i <= N; i++) {
        ll j = st.query(H[i], M);
        ans[i] = ans[j] + (i-j)*v[H[i]];
        st.update(H[i], i);
    }

    for (int i = 1; i <= N; i++) cout << ans[i]+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
