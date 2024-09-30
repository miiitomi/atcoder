// https://atcoder.jp/contests/abc130/tasks/abc130_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
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
        return a + b;
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
    vector<ll> S(N), T(M);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < M; i++) cin >> T[i];
    vector<vector<mint>> dp(N+1, vector<mint>(M+1, 0));
    dp[0][0] = 1;
    SegmentTree<mint> st(M+1);
    st.update(0, 1);
    mint ans = 1;
    for (int s = 0; s < N; s++) {
        for (int t = 0; t < M; t++) {
            if (S[s] != T[t]) continue;
            dp[s+1][t+1] = st.query(0, t+1);
            ans += dp[s+1][t+1];
        }
        for (int t = 1; t <= M; t++) st.update(t, dp[s+1][t]);
    }
    cout << ans.val() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
