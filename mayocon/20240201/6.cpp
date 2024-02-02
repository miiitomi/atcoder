// https://atcoder.jp/contests/abc283/tasks/abc283_f
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e+9;

template<typename T>
struct SegmentTree {
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
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    vector<int> ans(N, INF);

    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++) Q.push(make_pair(P[i], i));
    SegmentTree<int> st1(N), st2(N);
    while (!Q.empty()) {
        int i = Q.top().second, p = Q.top().first;
        Q.pop();
        ans[i] = min(ans[i], st1.query(0, i) - p + i);
        st1.update(i, p-i);
        ans[i] = min(ans[i], st2.query(i+1, N) - p - i);
        st2.update(i, p+i);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> R;
    for (int i = 0; i < N; i++) R.push(make_pair(P[i], i));
    SegmentTree<int> st3(N), st4(N);
    while (!R.empty()) {
        int i = R.top().second, p = R.top().first;
        R.pop();
        ans[i] = min(ans[i], st3.query(0, i) + p + i);
        st3.update(i, -p-i);
        ans[i] = min(ans[i], st4.query(i+1, N) + p - i);
        st4.update(i, -p+i);
    }

    for (int x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
