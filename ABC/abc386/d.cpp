#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1e+9;
const ll MOD = 998244353;

template<typename T> struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = INF;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return min(a, b);
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
    ll N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), C(M), v;
    for (int i = 0; i < M; i++) {
        char c;
        cin >> X[i] >> Y[i] >> c;
        v.push_back(X[i]);
        v.push_back(Y[i]);
        C[i] = (c == 'B');
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    N = v.size();
    SegmentTree<int> A(N+1), B(N+1);
    for (int i = 0; i < M; i++) {
        X[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), X[i]));
        Y[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), Y[i]));
        if (C[i] == 0) {
            A.update(X[i], Y[i]);
            B.update(Y[i], X[i]);
        }
    }
    for (int i = 0; i < M; i++) {
        if (C[i] == 0) continue;
        if (A.query(0, X[i]+1) < Y[i] || B.query(0, Y[i]+1) < X[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
