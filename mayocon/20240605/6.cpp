// https://atcoder.jp/contests/abc283/tasks/abc283_f
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmentTreeMax {
    int n;
    vector<T> data;
    T init_value = -1e+9;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTreeMax(int _n) {
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
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    SegmentTreeMax<int> stma1(N), stma2(N);
    vector<int> D(N, 1e+9);

    for (int i = 0; i < N; i++) {
        D[i] = min(D[i], P[i]+i - stma1.query(0, P[i]));
        D[i] = min(D[i], i-P[i] - stma2.query(P[i]+1, N));
        stma1.update(P[i], P[i]+i);
        stma2.update(P[i], i-P[i]);
    }

    SegmentTreeMax<int> stma3(N), stma4(N);
    for (int i = N-1; i >= 0; i--) {
        D[i] = min(D[i], P[i]-i - stma3.query(0, P[i]));
        D[i] = min(D[i], -(P[i]+i) - stma4.query(P[i]+1, N));
        stma3.update(P[i], P[i]-i);
        stma4.update(P[i], -P[i]-i);
    }

    for (int d : D) cout << d << " ";
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
