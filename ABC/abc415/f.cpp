#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

struct Data {
    char left_c = 'a', right_c = 'a', mid_c = 'a';
    int left = 0, right = 0, mid = 0, size = 0;
    Data() {}
    Data(char c) {
        left_c = c;
        right_c = c;
        mid_c = c;
        left = 1;
        right = 1;
        mid = 1;
        size = 1;
    }
};

struct SegmentTree {
    int n;
    vector<Data> data;
    Data init_value = Data();  // TODO: Set initial value of the data (e.g., INF if min, -INF if max, 0 if sum)

    SegmentTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        data.assign(2*n-1, init_value);
    }

    Data operation(Data &l, Data &r) {
        // TODO: Set operating function (e.g., min, max, sum)
        Data data;
        data.size = l.size + r.size;

        if (l.mid > r.mid) {
            data.mid = l.mid;
            data.mid_c = l.mid_c;
        } else {
            data.mid = r.mid;
            data.mid_c = r.mid_c;
        }

        if (l.right_c == r.left_c && l.right+r.left > data.mid) {
            data.mid = l.right+r.left;
            data.mid_c = l.right_c;
        }

        if (l.left == l.size && l.left_c == r.left_c) {
            data.left = l.left + r.left;
            data.left_c = l.left_c;
        } else {
            data.left = l.left;
            data.left_c = l.left_c;
        }

        if (r.right == r.size && r.right_c == l.right_c) {
            data.right = r.right+l.right;
            data.right_c = r.right_c;
        } else {
            data.right = r.right;
            data.right_c = r.right_c;
        }

        return data;
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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    SegmentTree st(N);
    for (int i = 0; i < N; i++) st.update(i, Data(S[i]));
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            st.update(i, Data(c));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.query(l, r).mid << "\n";
        }
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
