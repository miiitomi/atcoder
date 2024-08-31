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
    T init_value = {-INF, -1};  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        if (a.first < b.first) return b;
        return a;
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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
        P[i].first--; P[i].second--;
    }
    sort(P.begin(), P.end());
    P.push_back({H-1, W-1});
    SegmentTree<pair<ll,ll>> st(W);
    st.update(0, {0, 0});
    map<pair<ll,ll>, pair<ll,ll>> prev;
    for (pair<ll,ll> p : P) {
        pair<ll,ll> res = st.query(0, p.second+1);
        ll h = res.second/W, w = res.second%W;
        prev[p] = {h, w};
        st.update(p.second, make_pair(res.first + 1, p.first*W + p.second));
    }

    ll ans = st.query(W-1, W).first-1;
    cout << ans << endl;
    vector<pair<ll,ll>> path;
    pair<ll,ll> p = {H-1, W-1};
    while (p != make_pair(0LL, 0LL)) {
        path.push_back(p);
        p = prev[p];
    }
    reverse(path.begin(), path.end());
    string S = "";
    for (auto q : path) {
        for (int k = 0; k < (q.first - p.first); k++) S.push_back('D');
        for (int k = 0; k < (q.second - p.second); k++) S.push_back('R');
        p = q;
    }
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
