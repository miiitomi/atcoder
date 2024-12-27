// https://atcoder.jp/contests/abc165/tasks/abc165_f
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

int N;
vector<int> a;
vector<vector<int>> G;
vector<int> ans;

void dfs(int u, int p, SegmentTree<int> &st) {
    int o = st.query(a[u], a[u]+1);
    int res = st.query(0, a[u]);
    st.update(a[u], res+1);
    ans[u] = st.query(0, N);
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, st);
    }
    st.update(a[u], o);
}

void solve() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) a[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), a[i]));
    G.resize(N);
    for (int i = 0; i < N-1; i++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    ans.resize(N);
    SegmentTree<int> st(N);
    dfs(0, -1, st);
    for (int x : ans) {
        cout << x << "\n";
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
