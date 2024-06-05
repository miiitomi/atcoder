// https://atcoder.jp/contests/abc263/tasks/abc263_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector<vector<ll>> C(1 << N, vector<ll>(N+1, 0));
    for (int i = 0; i < (1 << N); i++) for (int j = 0; j < N; j++) cin >> C[i][j+1];

    vector<ll> dp((int)(1 << N), 0);
    vector<pair<int,int>> v((int)(1 << N), {0, 0});

    for (int i = 0; i < (1 << N); i++) v[i] = {i, i};
    int idx = 0;

    for (int k = 0; k < N; k++) {
        SegmentTree<ll> st((int)(1 << N));
        for (int i = 0; i < (int)(1 << N); i++) st.update(i, dp[i] + C[i][k]);
        vector<ll> ndp((int)(1 << N), 0);

        for (int i = 0; i < (int)(1 << N); i++) {
            pair<int,int> p;
            if (idx % 2 == 0) p = v[idx+1];
            else p = v[idx-1];
            ndp[i] = dp[i] + st.query(p.first, p.second+1);

            if (v[idx].second == i) idx++;
        }
        swap(dp, ndp);

        vector<pair<int,int>> w;
        for (int j = 0; j < (int)v.size(); j+=2) w.push_back({v[j].first, v[j+1].second});
        swap(v, w);
        idx = 0;
    }

    SegmentTree<ll> st((int)(1 << N));
    for (int i = 0; i < (1 << N); i++) st.update(i, dp[i] + C[i][N]);
    cout << st.query(0, (1 << N)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
