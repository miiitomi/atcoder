#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = 1e+18;  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

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

    // Return the answer in [i, j)
    T query(int i, int j) {
        return _sub_query(i, j, 0, 0, n);
    }
};

ll N, K, sx, sy;
vector<ll> X, Y;

double dist(ll sx_, ll sy_, ll tx_, ll ty_) {return sqrt((double)0.0 + (sx_ - tx_)*(sx_ - tx_) + (sy_ - ty_)*(sy_ - ty_));}
double dist(int s, int t) {return dist(X[s], Y[s], X[t], Y[t]);}
double dist(int s) {return dist(X[s], Y[s], sx, sy);}

int main() {
    cin >> N >> K >> sx >> sy;
    X.resize(N);
    Y.resize(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    vector<double> Z(N, 0);
    for (int i = 0; i < N-1; i++) Z[i+1] = dist(i) + dist(i+1) - dist(i, i+1);

    SegmentTree<double> st(N);  // data[i] で i にいく直前に家に戻った時の余分な移動距離の合計の最小値
    st.update(0, 0.0);
    for (int i = 1; i < N; i++) st.update(i, st.query(max(0LL, i-K), i) + Z[i]);

    double ans = 0.0;
    for (int i = 0; i < N-1; i++) {
        ans += dist(i, i+1);
    }
    ans += dist(0) + dist(N-1);
    ans += st.query(N-K, N);

    cout << fixed << setprecision(15) << ans << endl;
}
