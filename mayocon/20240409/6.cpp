// https://atcoder.jp/contests/abc331/tasks/abc331_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll b, MOD;
vector<ll> pow_b;

template<typename T>
struct SegmentTree {
    int n;
    vector<T> data;
    T init_value = make_pair(0, 0);  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    T operation(T a, T b) {
        // TODO: Set operating function (e.g., min, max, sum)
        return make_pair((a.first * pow_b[b.second] % MOD + b.first) % MOD, a.second + b.second);
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

void solve() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    SegmentTree<pair<ll,ll>> st_left(N), st_right(N);
    for (int i = 0; i < N; i++) {
        ll x = S[i] - 'a';
        st_left.update(i, make_pair(x, 1));
        st_right.update(N-1-i, make_pair(x, 1));
    }
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            ll x = c - 'a';
            st_left.update(i, make_pair(x, 1));
            st_right.update(N-1-i, make_pair(x, 1));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            ll L = st_left.query(l, r+1).first;
            ll R = st_right.query(N-1-r, N-1-l+1).first;
            if (L == R) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

bool is_prime(ll x) {
    for (ll y = 2; y*y <= x; y++) if (x % y == 0) return false;
    return true;
}

void preprocessing() {
    random_device rd;
    mt19937_64 engine(rd());
    uniform_int_distribution<> U((int)1e+9, (int)2e+9);
    MOD = U(engine);
    while (!is_prime(MOD)) MOD = U(engine);
    b = U(engine) % MOD;
    while (b < 100) b = U(engine) % MOD;

    pow_b.assign(1e+7, 1);
    for (ll x = 1; x < 1e+7; x++) pow_b[x] = pow_b[x-1] * b % MOD;
}

int main() {
    preprocessing();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
