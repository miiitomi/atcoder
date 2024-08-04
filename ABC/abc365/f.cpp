#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Data {
    ll f1, f2, g1, g2, c;
    Data(ll f1_, ll f2_, ll g1_, ll g2_, ll c_): f1(f1_), f2(f2_), g1(g1_), g2(g2_), c(c_) {}
    ll f(ll y) {return min(max(y, f1), f2);}
    ll clamp_g(ll y) {return min(max(y, g1), g2);}
    ll g(ll y) {return c + max(0LL, max(g1-y, y-g2));}
};

struct SegmentTree {
    int n;
    vector<Data> data;
    Data init_value = Data(1, (ll)1e+9, 1, (ll)1e+9, 0);  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    Data operation(Data a, Data b) {
        ll f1 = b.f(a.f1);
        ll f2 = b.f(a.f2);
        ll g1 = a.clamp_g(b.g1);
        ll g2 = a.clamp_g(b.g2);
        ll c = a.g(g1) + b.g(a.f(g1));
        return Data(f1, f2, g1, g2, c);
    }

    void update(int i, Data a) {
        // Update data[i] to a
        i = n - 1 + i;
        data[i] = a;  // TODO: Set update operation if needed (e.g. data[i] = a )
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i*2 + 1], data[i*2 + 2]);
        }
    }

    Data _sub_query(int i, int j, int k, int l, int r) {
        if (r <= i || j <= l) return init_value;
        if (i <= l && r <= j) return data[k];
        Data vl = _sub_query(i, j, 2*k + 1, l, (l + r)/2);
        Data vr = _sub_query(i, j, 2*k + 2, (l + r)/2, r);
        return operation(vl, vr);
    }

    Data query(int i, int j) {
        // Return the answer in [i, j)
        return _sub_query(i, j, 0, 0, n);
    }
};

void solve() {
    ll N;
    cin >> N;
    SegmentTree st(N+1);
    for (int i = 1; i <= N; i++) {
        ll l, u;
        cin >> l >> u;
        st.update(i, Data(l, u, l, u, 1));
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        if (sx == tx) {
            cout << abs(ty - sy) << "\n";
            continue;
        }
        if (sx > tx) {
            swap(sx, tx);
            swap(sy, ty);
        }
        Data res = st.query(sx+1, tx+1);
        ll y = res.f(sy), c = res.g(sy);
        cout << c + abs(y - ty) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
