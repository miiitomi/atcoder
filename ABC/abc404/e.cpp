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
    T init_value = 1e+9;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

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
    int N;
    cin >> N;
    vector<int> C(N, 0), A(N, 0);
    for (int i = 1; i < N; i++) cin >> C[i];
    for (int i = 1; i < N; i++) cin >> A[i];

    vector<SegmentTree<int>> dp(N, SegmentTree<int>(N));
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            if (r == l) {
                dp[l].update(r, 0);
            } else if (r-l <= C[r]) {
                dp[l].update(r, 1);
            } else {
                int tmp = dp[l].query(r-C[r], r);
                dp[l].update(r, tmp + 1);
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] == 0) continue;
        int tmp = dp[0].query(i, i+1);
        for (int j = 1; j < i; j++) {
            if (A[j]) {
                tmp = min(tmp, dp[j].query(i, i+1));
            }
        }
        ans += tmp;
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
