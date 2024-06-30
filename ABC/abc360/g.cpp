#include <bits/stdc++.h>
using namespace std;

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
    int N;
    cin >> N;
    vector<int> A(N), v;
    v.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(A[i]);
        v.push_back(A[i]+1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int M = v.size();
    for (int &a : A) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));

    vector<SegmentTree<int>> dp(2, SegmentTree<int>(M));
    dp[0].update(A[0], 1);
    dp[1].update(0, 1);
    for (int i = 1; i < N; i++) {
        int a = A[i], b = A[i-1]+1;
        dp[1].update(a, dp[1].query(0, a)+1);
        dp[0].update(a, dp[0].query(0, a)+1);
        dp[1].update(b, dp[0].query(b-1, b)+1);
    }
    int ans = dp[1].query(0, M);
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
