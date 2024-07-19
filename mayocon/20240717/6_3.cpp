// https://atcoder.jp/contests/abc334/tasks/abc334_f
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

double d(ll x1, ll y1, ll x2, ll y2) {return sqrt(0.0 + (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}
double d(pair<ll,ll> &p, pair<ll,ll> &q) {return d(p.first, p.second, q.first, q.second);}

void solve() {
    ll N, K;
    cin >> N >> K;
    pair<ll,ll> S;
    cin >> S.first >> S.second;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    SegmentTree<double> dp(N);
    dp.update(0, 0.0);
    for (int i = 1; i < N; i++) {
        dp.update(i, dp.query(max(i-K, 0LL), i) + d(V[i-1], S)+d(S, V[i])-d(V[i-1], V[i]));
    }
    double ans = d(S, V[0]) + d(V[N-1], S);
    for (int i = 1; i < N; i++) ans += d(V[i-1], V[i]);
    ans += dp.query(N-K, N);
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
