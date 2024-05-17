#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 3e+18;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = -INF;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

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
    ll N, C, M;
    cin >> N >> C >> M;
    vector<ll> T(M), P(M);
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> P[i];
        T[i]--;
    }

    vector<ll> dp(N, -INF);
    dp[0] = 0;
    SegmentTree<ll> st1(N), st2(N);
    st1.update(0, 0);
    st2.update(0, 0);

    for (int q = 0; q < M; q++) {
        ll t = T[q], p = P[q];
        dp[t] += p;
        dp[t] = max(dp[t], p - t*C + st1.query(0, t));
        dp[t] = max(dp[t], p + t*C + st2.query(t+1, N));
        st1.update(t, dp[t] + t*C);
        st2.update(t, dp[t] - t*C);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
