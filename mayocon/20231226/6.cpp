// https://atcoder.jp/contests/abc186/tasks/abc186_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        return a + b;
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

int main() {
    int H, W, M;
    cin >> H >> W >> M;

    vector<vector<int>> R(W+1), C(H+1);
    while (M--) {
        int x, y;
        cin >> x >> y;
        R[y].push_back(x);
        C[x].push_back(y);
    }
    for (int r = 0; r <= W; r++) if (!R[r].empty()) sort(R[r].begin(), R[r].end());
    for (int c = 0; c <= H; c++) if (!C[c].empty()) sort(C[c].begin(), C[c].end());

    ll ans = 1;
    vector<pair<ll, ll>> V;
    for (ll x = 2; x <= H; x++) {
        if (!R[1].empty() && x == R[1][0]) break;
        ll y = W;
        if (!C[x].empty()) y = C[x][0]-1;
        ans += y;
        V.push_back(make_pair(y, x));
    }

    sort(V.begin(), V.end());
    ll y = W;
    if (!C[1].empty()) y = C[1][0]-1;
    SegmentTree<ll> st(H+1);
    for ( ; y >= 2; y--) {
        while (!V.empty() && V.back().first >= y) {
            st.update(V.back().second, 1);
            V.pop_back();
        }
        ll x = H;
        if (!R[y].empty()) x = R[y][0]-1;
        ans += (x - st.query(0, x+1));
    }

    cout << ans << endl;
}
