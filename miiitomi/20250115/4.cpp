// https://atcoder.jp/contests/abc254/tasks/abc254_f
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
        return gcd(a, b);
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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    SegmentTree<ll> st1(N-1), st2(N-1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) st1.update(i-1, A[i] - A[i-1]);
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (i > 0) st2.update(i-1, B[i] - B[i-1]);
    }
    while (Q--) {
        ll h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--; w1--; h2--; w2--;
        ll ans = A[h1]+B[w1];
        if (h1 < h2) ans = gcd(ans, st1.query(h1, h2));
        if (w1 < w2) ans = gcd(ans, st2.query(w1, w2));
        cout << ans << "\n";
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
