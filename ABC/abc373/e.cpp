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
        return a+b;
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

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first;
        V[i].second = i;
        K -= V[i].first;
    }
    if (N == M) {
        for (int i = 0; i < N; i++) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }
    sort(V.begin(), V.end());
    SegmentTree<ll> st(N);
    for (int i = 0; i < N; i++) st.update(i, V[i].first);
    vector<ll> ans(N);
    for (int i = 0; i < N; i++) {
        ll left = -1, right = K+1;
        int l = N-M;
        if (l <= i) l--;
        while (right - left > 1) {
            ll x = (left + right)/2;
            auto iter = lower_bound(V.begin(), V.end(), make_pair(V[i].first+x+1LL, -1LL));
            int j = distance(V.begin(), iter);
            if (j <= l) {
                left = x;
                continue;
            }
            ll sum = st.query(l, j);
            if (l <= i && i < j) sum -= V[i].first;
            ll r = (M - (N-j))*(V[i].first+x+1) - sum;
            if (x + r <= K) left = x;
            else right = x;
        }
        ans[V[i].second] = right;
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] <= K) cout << ans[i];
        else cout << -1;
        if (i < N-1) cout << " ";
        else cout << "\n";
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
