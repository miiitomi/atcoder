#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M, K;
vector<ll> v;
set<int> S;

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
        return a+b;
    }

    // Update data[i] to a.
    void update(int i, T a) {
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

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

int answer_query(SegmentTree<ll> &exists_vertex, SegmentTree<ll> &exists_edge_to_right, int x) {
    int l = x, r = M;
    while (r-l > 1) {
        int m = (l + r) / 2;
        if (exists_vertex.query(x, m) == exists_edge_to_right.query(x, m)) l = m;
        else r = m;
    }
    int R = r;

    l = -1;
    r = x;
    while (r-l > 1) {
        int m = (l + r) / 2;
        if (exists_vertex.query(m, x) == exists_edge_to_right.query(m, x)) r = m;
        else l = m;
    }
    int L = l+1;
    return exists_vertex.query(L, R);
}

pair<int,int> return_l_r(int x) {
    int L = -1, R = M;
    auto iter = S.lower_bound(x+1);
    if (iter != S.end()) R = *iter;
    iter = S.lower_bound(x);
    if (iter != S.begin()) {
        iter--;
        L = *iter;
    }
    return {L, R};
}

void add_query(SegmentTree<ll> &exists_vertex, SegmentTree<ll> &exists_edge_to_right, int x) {
    auto [L, R] = return_l_r(x);
    exists_vertex.update(x, 1);
    if (R < M && v[R]-v[x] <= K) exists_edge_to_right.update(x, 1);
    if (L >= 0 && v[x]-v[L] <= K) exists_edge_to_right.update(L, 1);
}

void minus_query(SegmentTree<ll> &exists_vertex, SegmentTree<ll> &exists_edge_to_right, int x) {
    exists_vertex.update(x, 0);
    exists_edge_to_right.update(x, 0);
    auto [L, R] = return_l_r(x);
    if (L != -1) {
        exists_edge_to_right.update(L, 0);
        if (R < M && v[R]-v[L] <= K) exists_edge_to_right.update(L, 1);
    }
}

void solve() {
    ll Q;
    cin >> Q >> K;
    vector<ll> T(Q), X(Q);
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> X[i];
        v.push_back(X[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < Q; i++) X[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), X[i]));

    M = v.size();
    SegmentTree<ll> exists_vertex((int)v.size());
    SegmentTree<ll> exists_edge_to_right((int)v.size());

    for (int q = 0; q < Q; q++) {
        if (T[q] == 1) {
            int x = X[q];
            if (S.count(x)) {
                minus_query(exists_vertex, exists_edge_to_right, x);
                S.erase(x);
            } else {
                add_query(exists_vertex, exists_edge_to_right, x);
                S.insert(x);
            }
        } else {
            int x = X[q];
            int ans = answer_query(exists_vertex, exists_edge_to_right, x);
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
